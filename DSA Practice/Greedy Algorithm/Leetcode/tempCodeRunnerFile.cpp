
        if(s.size()==0)   return true;

        // Creating two pointers
        int i=0,j=0; 

        for(;j<t.size();j++){
            // If the element is available in t
            // increase pointer in s
            if(i<s.size() && t[j]==s[i])    i++;     
        }

        // i becomes equal to size of s, that means every element is available
        if(i==s.size()) return true;
        
        //If not, returning false
        return false;
    }
};