// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

class RandomizedSet {
    set<int>s;
public:
    RandomizedSet() {
        
    }
    bool insert(int val) {
        if(s.find(val) != s.end()){
            return false;
        }
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()){
             s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int l = 0 , r = s.size() - 1;
        int idx = l + ( rand() % ( r - l + 1 ) );
        return *next(s.begin(), idx);
    }
};
