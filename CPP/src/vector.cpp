include <vector>


/* ---------------------------- 判断Vector中是否存在某个元素 --------------------------- */
bool is_element_in_vector(std::vector<int> v,int element){
    std::vector<int>::iterator it;
    it = find(v.begin(),v.end(),element);
    if (it != v.end()){
        return true;
    }
    else{
        return false;
    }
}

/* ----------------------------- 寻找元素在Vector的位置 ----------------------------- */
int findPosVector(std::vector <int> input , int number)
{
    std::vector<int>::iterator iter = std::find(input.begin(), input.end(), number); //返回的是一个迭代器指针
    if(iter == input.end())
    {
        return -1;
    } else{
        return std::distance(input.begin(), iter);
    }
}


/* ------------------------------- 容器Vector中去重 ------------------------------ */
std::vector<int> unique_element_in_vector(std::vector<int> v) {
    std::vector<int>::iterator vector_iterator;
    sort(v.begin(), v.end());
    vector_iterator = unique(v.begin(), v.end());
    if (vector_iterator != v.end()) {
        v.erase(vector_iterator, v.end());
    }
    return v;
}

/* ------------------------------- 两个Vector求交集 ------------------------------ */
std::vector<int> vectors_intersection(std::vector<int> v1, std::vector<int> v2){
	vector<int> v;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v)); //求交集
	return v;
}


/* ------------------------------- 两个Vector并集 ------------------------------- */
std::vector<int> vectors_set_union(std::vector<int> v1, std::vector<int> v2){
	vector<int> v;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v));//求交集
	return v;
}
