#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class BinomialHeap{
	private:
		struct BinTree{
			T data;
			BinTree*child, *sibling;
			
			BinTree(T d, BinTree* c, BinTree *s){
				data = d;
				child = c;
				sibling = s;
			}
		};
		int count;
		vector<BinTree*> trees;
		BinTree* mergeTrees(BinTree *lhs, BinTree *rhs){
			if(lhs == NULL) 
				return rhs; 
			if(rhs == NULL) 
				return lhs;
			if(rhs->data < lhs->data) 
				std::swap(lhs, rhs);
			rhs->sibling = lhs->child;
			lhs->child = rhs; 
			return lhs;
		}
		int min_index();
		void deleteTree(BinTree* cur){
			if(cur==NULL)
				return;
			deleteTree(cur->sibling);
			deleteTree(cur->child);
			delete cur;
		}
		void setTree(BinTree* cur){
			if(cur==NULL)
				return;
			setTree(cur->child);
			setTree(cur->sibling);
			push(cur->data);
		}
	public:
		BinomialHeap(){count = 0;}
		BinomialHeap(const BinomialHeap& other){
			this = other;
		}
		~BinomialHeap(){
			for(int i=0; i<trees.size(); i++)
				if(trees[i] != NULL )
					deleteTree(trees[i]);
		}
		BinomialHeap& operator=(const BinomialHeap& other){
			for(int i=0; i<other.trees.size(); i++)
					setTree(other.trees[i]);
			return *this;	
		}

		void push(T);
		void pop();
		T top();
		int size();

		void mergeHeaps(std::vector<BinTree*> &lhs, std::vector<BinTree*>&rhs){
			std::vector<BinTree *> result;
			BinTree *carry = NULL; 
			int max_order = std::max(lhs.size(), rhs.size());
			lhs.resize(max_order); 
			rhs.resize(max_order);
			for(int order = 0; order < max_order; order++){
				std::vector<BinTree *> tmp; 
				if(carry) 
					tmp.push_back(carry); 
				if(lhs[order]) 
					tmp.push_back(lhs[order]); 
				if(rhs[order]) 
					tmp.push_back(rhs[order]);
				if(tmp.empty()){				//case 0
					result.push_back(NULL);
					carry = NULL;
				}
				if(tmp.size()==1){				//case 1
					result.push_back(tmp[0]);
					carry = NULL;
				}	
				if(tmp.size()==2){				//case 2
					result.push_back(NULL);
					carry = mergeTrees(tmp[0],tmp[1]);
				}
				if(tmp.size()==3){
					result.push_back(tmp[0]);	//case 3
					carry = mergeTrees(tmp[1],tmp[2]);
				}
					 
//Case 0: All trees are NULL (0 + 0 = 0) }else if(tmp.size() == 1){ //Case 1: One tree is not NULL (1 + 0 = 0) }else if(tmp.size() == 2){

//Case 2: Two trees are not NULL (1 + 1 = 0 carry1)
//Case 3: 3 trees are not NULL }else if(tmp.size() == 3){
//Case 4: Three trees are not NULL (1 + 1 with	carry = 1 carry 1)
			}
			if(carry)	
				result.push_back(carry);
			rhs.clear(); 
			trees = result;
		}

};
template<typename T>
void BinomialHeap<T>::push(T entry){
	vector<BinTree*> temp;
	temp.push_back(new BinTree(entry,NULL, NULL));
	mergeHeaps(temp, trees);
	count++;
}

template<typename T>
void BinomialHeap<T>::pop(){
	if(size()==0)
		cout<<"EMPTY"<<endl;
	count--;
	BinTree* min_tree = trees[min_index()];
	trees[min_index()] = NULL;
	vector<BinTree*> temp;
	BinTree* tmp = min_tree;
	min_tree = min_tree->child;
	delete tmp;

	while(min_tree!=NULL){
		temp.push_back(min_tree);
		min_tree = min_tree->sibling;
	}
	vector<BinTree*> reversed;
	for(int i=temp.size()-1; i>=0; i--){
		temp[i]->sibling=NULL;
		reversed.push_back(temp[i]);
	}
	mergeHeaps(reversed, trees);

	
}

template<typename T>
T BinomialHeap<T>::top(){
	if(size()==0)
		cout<<"EMPTY"<<endl;
	return trees[min_index()]->data;
}

template<typename T>
int  BinomialHeap<T>::size(){
	return count;	
}

template<typename T>
int  BinomialHeap<T>::min_index(){
	bool flag_first = true;
	int min_index;
	for(int i=0; i<trees.size(); i++){
		if(trees[i]!=NULL){
			if(flag_first){
				flag_first = false;
				min_index = i;
			}else{
				if(trees[i]<trees[min_index])
					min_index = i;
			}				
		}
	}
	return min_index;
}
	
