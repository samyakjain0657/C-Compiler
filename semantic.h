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

extern int yylineno;
// Nodes of the AST
struct DataNode {
public:
	string type;			// lexeme class
	string value;			// lexeme
	DataType data_type;		// datatype of the Datanode(if required)
	int line_number;		// line number where the Datanode is occuring

	// Children of the DataNodes
	DataNode *child1;
	DataNode *child2;
	DataNode *child3;
	DataNode *child4;

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

int scope;

vector <string> var_list;
vector <DataType> param_list;
vector <int> dimlist;

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
    
    auto param_list=fnptr->paramlist;
    
    for(auto it=param_list.begin();it!=param_list.end();it++){
		
		if((it)->name==p){
			found=true;
			pnptr=&(*it);
		}
		else{
			found=false;
			pnptr=NULL;
		}
    }
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
    auto local_list=fnptr->local_var_list;
    
    for(auto it=local_list.begin();it!=local_list.end();it++){
		for(int i=level;i!=0;i--){
			if((it)->name==p && (it)->level==i){
				found=true;
				vn=&(*it);
				return;
			}
		}
    }
	found=false;
	vn=NULL;
}

void delete_var_list(func_table_entry* func, int level){
	
	auto var_list=func->local_var_list;
    
    for(auto it=var_list.begin();it!=var_list.end();it++){
		if((it)->level==level){
			var_list.erase(it);
		}
    }
}

void enter_func(string name, string result_type, func_table_entry* &namptr){
	func_table_entry* new_entry=new func_table_entry();
	
	new_entry->name=name;
	new_entry->result_type=result_type;

	namptr=new_entry;

	func_table.insert({name,*new_entry});

}

void enter_param(string name,string type,func_table_entry* func,var* &pnptr){

	bool found = false;
	var* new_param=new var();
	search_param(name, func, found, new_param);
	if(found){
		cout<<"Parameter "<<name<<" already declared in this function"<<endl;
		return;
	}


	new_param->name=name;
	new_param->isParam=true;
	new_param->level=1;
	new_param->type="simple";
	new_param->eletype=type;

	pnptr=new_param;

	(func->paramlist).push_back(*new_param);

}

void enter_var(string name,int level,string type,vector <int> &dims,func_table_entry* func){
	bool found = false,found1=false;
	var* variable = new var();
	var *variable1;
	if(level!=0)
		search_func(func->name,found1,func);
	search_var(name, func, level, found, variable1);
	if(found){
		cout << "Error " << yylineno << " : Variable " << name << " already declared " << endl; 
		dimlist.clear();
		return;
	}
	else if(level==2){
		var* param;
		search_param(name,active_func_ptr,found,param);
		if(found){
			cout << "Error " << yylineno << " : Variable " << name << " already declared as parameter" << endl; 
			dimlist.clear();
			return;
		}
	}
	variable->name = name;
	variable->level = level;
	variable->type = type;
	if(type=="array")
		variable->dims = dims;
	var_list.push_back(name);

	// if(func!=NULL)
	// 	cout<<func->name<<" "<<name<<endl;
	if(level==0){
		sym_tab.insert({name,*variable});	
	}
	else {
		func->local_var_list.push_back(*variable);
		// for (auto it : func->local_var_list) {
		// 	it.print();
		// }
	}

	dimlist.clear();	
}

void patch_type(string data_type){
	func_table_entry *func;
	bool found;
	for(int i=0;i<var_list.size();i++){
		if(scope==0){
			sym_tab[var_list[i]].eletype = data_type;
			
		}
		else{
			search_func(active_func_ptr->name,found,func);
			for(auto itr= func->local_var_list.begin();itr!=func->local_var_list.end();itr++){
				if((*itr).name==var_list[i] && (*itr).level==scope){
					(*itr).eletype = data_type;
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
				if(((*it).eletype=="integer")&&(param_list[j]==1)){

				}
				else if(((*it).eletype=="real")&&(param_list[j]==4)){

				}
				else{
					flag=1;
					break;
				}
			}
			if(flag==1){
				cout<<"Datatype not same in parameter list of function definition and caller function of function "<<func->name<<endl;
				res->data_type = dt_err;
				return res;
			}
			if (func->result_type == "integer") {
				res->data_type = dt_int;
			}
			else if (func->result_type == "real") {
				res->data_type = dt_float;
			}
			return res;
		}
		else{
			cout<<"Number of parameter list of function definition and caller function of function "<<func->name<<" are not same"<<endl;		
			res->data_type = dt_err;
			return res;		
		}
	}
	else{
		cout<<"Function "<<name<<" is not present"<<endl;
		res->data_type = dt_err;
		return res;	
	}
}

void print_tables(){
	cout<<"tables"<<endl;
}

