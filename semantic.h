// TODO
// array float c
// function return type
// Multiple syntax error
// int float conversion
// not op
// negative values

#include <bits/stdc++.h>
using namespace std;

enum DataType{
	dt_none,
	dt_int,
	dt_char,
	dt_string,
	dt_float,
	dt_bool,
	dt_func,
	dt_err
};

ofstream file;
ofstream symfile;

extern int yylineno;
// Nodes of the AST
struct DataNode {
public:
	string type;			// lexeme class
	string value;			// lexeme
	DataType data_type;		// datatype of the Datanode(if required)
	string code_name;
	int line_number;		// line number where the Datanode is occuring

	// Children of the DataNodes
	DataNode *child1;
	DataNode *child2;
	DataNode *child3;
	DataNode *child4;

	DataNode () {}

	DataNode (string t, string v, DataNode *c1, DataNode *c2, DataNode *c3) {
		type = t;
		value = v;
		data_type = dt_none;
		child3 = c3;
		child2 = c2;
		child1 = c1;
		child4 = NULL;
		line_number = yylineno;
	}

	void addChild4(DataNode *c4){
		child4 = c4;
	}

	string getValue(){
		return value;
	}

	string getType(){
		return type;
	}

	DataType getDataType(){
		return data_type;
	}

	void setDataType(DataType dt){
		data_type = dt;
	}
};

// DataNode* initialise (string c, string v){
        
// 	//Initialising a new code
// 	DataNode *d = new DataNode( c,v,NULL,NULL,NULL);

// 	return d;
// }

struct var{
    string type;
    string name;
	string code_name;
	string value;
    bool isParam;
    int level;
    string eletype;
    vector <int> dims;

	void print() {
		cout << type << " " << name << " " << isParam << " " << level << " " << eletype << " ";
		for (auto it: dims) {
			cout << '[' << it << ']' ;
		}
		cout << endl;
	}
};

struct func_table_entry {
    string name;
    string result_type;
    vector <var> paramlist;
    vector <var> local_var_list;

	void print() {
		cout << name << " " << result_type << "\n";
		cout << "Paramlist: \n";
		for (auto it: paramlist) {
			it.print();
		}
		cout << "local Varlist: \n";
		for (auto it: local_var_list) {
			it.print();
		}
	}
};

map <string, func_table_entry> func_table;
map <string, var> sym_tab;
DataType active_type = dt_none;

int var_counter = 0;
int dim_count = 0;
int param_count = 0;
int res_counter = 0;
int if_counter = 0;
int loop_counter = 0;
int switch_counter = 0;
int case_counter = 0;
int cond_counter = 0;
int func_dec_counter = 0;
string glob_val = "0";
string curr_temp;
int scope;

set<string> my_errors;
vector <string> var_list;
vector < pair<string, DataType > > param_list;
vector <int> dimlist;
vector <string> dimlist_call;
vector <var> symbol_list;
vector <string> temp_regs({"$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$t8","$t9"});
stack <int> if_stack, loop_stack, last_used, switch_stack, cond_stack;

func_table_entry* active_func_ptr=NULL;
func_table_entry* call_name_ptr = NULL;

void search_func(string n, bool &found, func_table_entry* &fnptr){
    auto it=func_table.find(n);
    
    if(it==func_table.end()){
        found=false;
        fnptr=NULL;
    }
    else{
        found=true;
        fnptr=&(it->second);
    }
}

void search_param(string p, func_table_entry* fnptr, bool &found, var* &pnptr){
    auto &param_list=fnptr->paramlist;
    
    for(auto it=param_list.begin();it!=param_list.end();it++){
		
			if((*it).name==p){
				found=true;
				pnptr=&(*it);
				return;
			}
    }

	found=false;
	pnptr=NULL;
}

void search_var(string p, func_table_entry* fnptr, int level, bool &found, var* &vn){
	if(fnptr==NULL){
		auto it=sym_tab.find(p);		
		if(it==sym_tab.end()){
			found=false;
			vn=NULL;
		}
		else{
			found=true;
			vn=&(it->second);
		}
		return;
	}
	bool found1 = false;
	if(level!=0)
		search_func(fnptr->name,found1,fnptr);    
    for(auto it=fnptr->local_var_list.begin();it!=fnptr->local_var_list.end();it++){
			for(int i=level; i >= 2; i--){
				if((it)->name==p && (it)->level==i){
					found=true;
					vn=&(*it);
					return;
				}
			}
    }
	search_param(p, fnptr, found, vn);
	if (found) {
		return;
	}
	else {
		auto it=sym_tab.find(p);
		if(it==sym_tab.end()){
			found=false;
			vn=NULL;
		}
		else{
			found=true;
			vn=&(it->second);
		}
		return;
	}
}

void search_var_level(string p, func_table_entry* fnptr, int level, bool &found, var* &vn){
	if(fnptr==NULL){
		auto it=sym_tab.find(p);
		
		if(it==sym_tab.end()){
			found=false;
			vn=NULL;
		}
		else{
			found=true;
			vn=&(it->second);
		}
		return;
	}
    auto &local_list = fnptr->local_var_list;
    
    for(auto it=local_list.begin();it!=local_list.end();it++){
		if((it)->name==p && (it)->level==level){
			found=true;
			vn=&(*it);
			return;
		}
    }
	found=false;
	vn=NULL;
}

void release_var(func_table_entry* &func, int level){
	bool found=false;
	if(level!=0)
		search_func(func->name,found,func);
    
    for(auto it=func->local_var_list.begin();it!=func->local_var_list.end();){
		if((it)->level==level){
			it = func->local_var_list.erase(it);
		}
		else
			it++;
    }
}

void enter_func(string name, string result_type, func_table_entry* &namptr){
	func_table_entry* new_entry = new func_table_entry;
	
	new_entry->name=name;
	new_entry->result_type=result_type;

	namptr=new_entry;

	func_table.insert({name,*new_entry});
}

void enter_param(string name, string type, func_table_entry* &func, var* &pnptr){

	bool found = false;
	bool found1 = false;
	var* new_param=new var();
	var* new_param1;
	// cout<<scope<<endl;
	if(scope!=0)
		search_func(func->name,found1,func);
	search_param(name, func, found, new_param1);
	if(found){
		cout<<"Parameter "<<name<<" already declared in this function"<<endl;
		return;
	}

	new_param->name=name;
	new_param->isParam=true;
	new_param->level=1;
	new_param->type="simple";
	new_param->eletype=type;
	new_param->code_name = "_param" + to_string(param_count++);
	pnptr=new_param;

	(func->paramlist).push_back(*new_param);

}

void enter_var(string name, int level, string type, vector <int> &dims, func_table_entry* &func){
	bool found = false,found1=false;
	var* variable = new var();
	var *variable1;
	if(level!=0)
		search_func(func->name,found1,func);

	search_var_level(name, func, level, found, variable1);
	if(found){
		cout << "Line No. "<< yylineno <<" Error " << " : Variable " << name << " already declared " << endl; 
		dimlist.clear();
		return;
	}
	else if(level==2){
		var* param;
		search_param(name, func, found, param);
		if(found){
			cout << "Line No. "<< yylineno <<" Error " << " : Variable " << name << " already declared as parameter" << endl; 
			dimlist.clear();
			return;
		}
	}
	variable->name = name;
	variable->level = level;
	variable->type = type;
	variable->value = glob_val;
	variable->code_name = "_var" + to_string(var_counter++);
	if(type=="array") {
		// variable->dims = dims;
		variable->dims.resize(dims.size());
		for (auto i = 0; i < dims.size(); i++) {
			variable->dims[i] = dims[i];
		}
	}
	var_list.push_back(name);

	if(level==0){
		sym_tab.insert({name,*variable});	
	}
	else {
		func->local_var_list.push_back(*variable);
	}
	glob_val = "0";
	dimlist.clear();	
}

void patch_type(string data_type){
	func_table_entry *func;
	bool found;
	for(int i=0;i<var_list.size();i++){
		if(scope==0){
			sym_tab[var_list[i]].eletype = data_type;
			symbol_list.push_back(sym_tab[var_list[i]]);
		}
		else{
			search_func(active_func_ptr->name,found,func);
			for(auto itr= func->local_var_list.begin();itr!=func->local_var_list.end();itr++){
				if((*itr).name==var_list[i] && (*itr).level==scope){
					(*itr).eletype = data_type;
					symbol_list.push_back(*itr);
					break;
				}
			}
		}	
	}

	var_list.clear();
}

DataNode* check_func_call(string name){
	func_table_entry* func;
	DataNode* res = new DataNode("FUNC", name, NULL, NULL, NULL);
	bool found;
	search_func(name,found,func);
	if(found){
		if(func->paramlist.size()==param_list.size()){
			int flag=0;
			int j=0;
			for(auto it=func->paramlist.begin();it!=func->paramlist.end();it++,j++){
				if(((*it).eletype=="int")&&(param_list[j].second==dt_int)){

				}
				else if(((*it).eletype=="float")&&(param_list[j].second== dt_float)){

				}
				else{
					cout << "Line no. " << yylineno << " Error: " << "incompatible type for argument " << j << " of function '" << name << "' " << endl;					
				}
			}
			if(flag==1){
				res->data_type = dt_err;
				return res;
			}
			if (func->result_type == "int") {
				res->data_type = dt_int;
			}
			else if (func->result_type == "float") {
				res->data_type = dt_float;
			}
			else {
				res->data_type = dt_none;
			}
			return res;
		}
		else{
			cout << "Line no. " << yylineno << " Error: " << "no. of arguments to function '"<<func->name<<"' mismatch"<<endl;		
			res->data_type = dt_err;
			return res;		
		}
	}
	else{
		cout << "Line no. " << yylineno << " Error: " <<"Function '"<<name<<"' is not present"<<endl;
		res->data_type = dt_err;
		return res;	
	}
}

// void print_tables(){
// 	cout<<"tables"<<endl;
// }

DataNode* typecaster(DataNode* a, DataNode* b) {
	if (a->data_type == dt_err)
		return a;
	if (b->data_type == dt_err) 
		return b;
	if (a->data_type == dt_float && b->data_type == dt_float)
		return a;
	else if (a->data_type == dt_float && b->data_type == dt_int)
		return a;
	else if (a->data_type == dt_int && b->data_type == dt_float)
		return b;
	else if (a->data_type == dt_int && b->data_type == dt_int)
		return a;

	DataNode* res = new DataNode();
	res->data_type = dt_err;
	return res;
}

DataNode* checkType(DataNode *a, DataNode* b) {
	bool found = false;
	var* variable;
	search_var(a->value, active_func_ptr, scope, found, variable);
	if (!found) {
		cout << "Line No. " << yylineno << " Error: variable '" << a->value << "' not found." << endl;
		DataNode* res = new DataNode;
		res->data_type = dt_err;
		return res; 
	}
	if (b->data_type == dt_int && variable->eletype == "int") {
		return b;
	}
	else if (b->data_type == dt_float && variable->eletype == "float") {
		return b;
	}
	else {
		cout << "Line No. " << yylineno << " Error: Type of variable '"<< variable->name << "' does not match with right hand side." << endl;
		DataNode* res = new DataNode;
		res->data_type = dt_err;
		return res;
	}
}

bool check_type(DataNode*b, DataNode *a) {
	if (active_type != a->data_type) {
		cout << "Line No. " << yylineno << " Error: Type of variable '" << b->value <<"' does not match with right hand side." << endl;
		return 0;
	}
	b->data_type = active_type;
	return 1;
}

DataNode* check_func_return_type(DataNode* a) {
	if (a->data_type == dt_int && active_func_ptr->result_type == "int")
		return a;
	else if (a->data_type == dt_float && active_func_ptr->result_type == "float")
		return a;
	else {
		cout << "Line No. " << yylineno << " Error: result type of function does not match with expression." << endl;
		DataNode* res = new DataNode;
		res->data_type = dt_err;
		return res;
	}
}

void set_data_type(DataNode* &a) {
	bool found = false;
	var* variable;
	search_var(a->value, active_func_ptr, scope, found, variable);
	if (!found) {
		cout << "Line No. " << yylineno << " Error: variable '" << a->value << "' not found." << endl;
		a->data_type = dt_err;
		return;
	}
	if (variable->eletype == "int") {
		a->data_type = dt_int;
	}
	else {
		a->data_type = dt_float;
	}
}

string get_var_code_name(string name) {
	bool found = false;
	var *variable;
	search_var(name,active_func_ptr,scope,found,variable);
	if(!found){
		cout << "Line No. " << yylineno << " Error: variable '" << name << "' not found." << endl;
	}
	else{
		return variable->code_name;
	}
}

string get_temp_name(){
	if (temp_regs.size() > 0) {
		string s = temp_regs[temp_regs.size()-1];
		temp_regs.pop_back();
		// cout << "acquired : " << s << endl;
		return s;
	}
	return "";
}

void release_temp_name(string s){
	if(s[0] !='$' || s == "")
		return;
	// cout << "released : " << s << endl;
	temp_regs.push_back(s);
}

vector <int> get_dimlist(string name){
	func_table_entry* func;
	bool found = false, found1;
	search_func(active_func_ptr->name,found1,func);
	var *variable;
	search_var(name,func,scope,found,variable);
	if(!found){
		cout << "Line No. " << yylineno << " Error: variable '" << name << "' not found." << endl;
	}
	else{
		return variable->dims;
	}
}

void print_symbol_list() {
	for (auto it: symbol_list) {
		if (it.type == "simple") {
			symfile << it.code_name << ":\t\t.word "<< it.value << "\n";
		}
		else {
			int n = 1;
			for (auto it2 : it.dims) {
				n = n*it2;
			}
			symfile << it.code_name << ":\t\t.space\t" << n*4 << endl;
		}
	}
}