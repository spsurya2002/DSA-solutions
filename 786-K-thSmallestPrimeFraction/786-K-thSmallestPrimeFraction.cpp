    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float,pair<int,int>>>p;
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                p.push_back({(arr[i]/(1.0*arr[j])),{arr[i],arr[j]}});
            }
            
        }sort(p.begin(),p.end());
public:
        return {p[k-1].second.first,p[k-1].second.second};
    }
[
