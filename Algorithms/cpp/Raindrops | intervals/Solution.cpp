// https://aaronice.gitbook.io/lintcode/company-tag/google/raindrop-on-sidewalk
// When it rains, each raindrop could cover a certain area. If we have an array of each raindrop, could you tell k that the first k raindrops can final make this sidewalk all wet?
// The input will be a 2-dimenstion array. Sidewalk will be [0,1] always N lines with 2 numbers in each line, meaning the range that a raindrop could cover. Return k if the first k raindrop could already cover the sidewalk. Return -1 if all the raindrops can still not cover the sidewalk. 

// 2d array, the second dimension will always be 2 elements
// 4     --> number of raindrop array
// 2     --> the second dimension will always be 2 elements
// 0     --> 1st raindrop array
// 0.3   --> 1st raindrop array
// 0.5   --> 2nd raindrop array
// 0.8   --> 2nd raindrop array
// 0.76  --> 3rd raindrop array
// 1     --> 3rd raindrop array
// 0.6   --> 4th raindrop array
// 0.98  --> 4th raindrop array

int rainDrops(vector < vector < double > > rain) {
    vector<vector<double>> sidewalk = {{0.0, 1.0}};
    auto apply_raindrop = [&](int idx) -> void {
        for(int i = sidewalk.size() - 1; i >= 0; i--){
            if(sidewalk[i][0] <= rain[idx][0] && sidewalk[i][1] >= rain[idx][0]){
                if(sidewalk[i][0] < rain[idx][0]){
                    sidewalk.push_back({sidewalk[i][0], rain[idx][0]});
                }
                if(sidewalk[i][1] > rain[idx][1]){
                    sidewalk.push_back({rain[idx][1], sidewalk[i][1]});
                }
                sidewalk.erase(sidewalk.begin() + i);
            }
            else if(rain[idx][0] <= sidewalk[i][0] && sidewalk[i][0] <= rain[idx][1]){
                if(sidewalk[i][1] > rain[idx][1]){
                    sidewalk.push_back({rain[idx][1], sidewalk[i][1]});
                }
                sidewalk.erase(sidewalk.begin() + i);
            }
        }
    };
    for(int k = 0; k < rain.size(); k++){
        apply_raindrop(k);
        if(sidewalk.empty()) return k + 1;
    }
    return -1;
}