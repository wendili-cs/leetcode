// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> sup;
        for(string& supply:supplies) sup.insert(supply);
        bool rescan = true;
        vector<string> res;
        while(rescan){
            rescan = false;
            for(int i = recipes.size() - 1; i >= 0; i--){
                bool can_make = true;
                for(string& ing:ingredients[i]){
                    if(sup.find(ing) == sup.end()){
                        can_make = false;
                        break;
                    }
                }
                rescan |= can_make;
                if(can_make){
                    sup.insert(recipes[i]);
                    res.push_back(recipes[i]);
                    recipes.erase(recipes.begin() + i);
                    ingredients.erase(ingredients.begin() + i);
                }
            }
        }
        return res;
    }
};