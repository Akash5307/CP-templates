template < typename T = int > struct Kadane {
    
    // Minimum Contigours Subarray Sum

    Kadane(){};

    T Min_Subarray_Sum(vector < T >& nums){
        T Min_so_far = OO, Min_Curr = 0, DEFAULT = 0;
        for(auto& i : nums){
            Min_Curr += i;
            Min_so_far = min(Min_so_far, Min_Curr);
            Min_Curr = min(Min_Curr, DEFAULT);
        }
        return Min_so_far;
    }

    // Maximum Contigours Subarray Sum

    T Max_Subarray_Sum(vector < T >& nums){
        T Max_so_far = -OO, Max_Curr = 0, DEFAULT = 0;
        for(auto& i : nums){
            Max_Curr += i;
            Max_so_far = max(Max_so_far, Max_Curr);
            Max_Curr = max(Max_Curr, DEFAULT);
        }
        return Max_so_far;
    }

};
