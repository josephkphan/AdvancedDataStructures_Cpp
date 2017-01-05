//map.h
#include<list>
#include<utility>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

template<typename K, typename V>
class Map{
	private:
		list< pair<K,V> > L;
	public:
		void insert(K key, V value);
		bool contains_key(K key);
		V value_of(K key);
		void remove_key(K key);	
		
		friend ostream& operator<<(ostream &out, const Map<K,V>& other){
			for (typename list< pair<K,V> >::const_iterator it = other.L.begin(); it != other.L.end(); it++){
				out << it->first<< " "<<it->second << ", ";
			}   
		  return out;
		}
		
};
template<typename K, typename V>
void Map<K,V>::insert(K key, V value){
	if(!contains_key(key)){
	
		L.push_back(make_pair(key,value));
	}
}

template<typename K, typename V>
bool Map<K,V>::contains_key(K key){
	for (typename list< pair<K,V> >::iterator it = L.begin(); it != L.end(); it++){
		if(it->first == key)
			return true;
	}		
	return false;

}

template<typename K, typename V>
V Map<K,V>::value_of(K key){
	for (typename list< pair<K,V> >::iterator it = L.begin(); it != L.end(); it++){
		if(it->first == key)
			return it->second;
	}
	cout<<"not found";
	return V();		

}

template<typename K, typename V>
void Map<K,V>::remove_key(K key){
	for (typename list< pair<K,V> >::iterator it = L.begin(); it != L.end(); it++){
		if(it->first == key){
			L.erase(it);
			break;
		}
	}		
		
}

