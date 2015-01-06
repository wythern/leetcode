#include "common.h"

class Solution {
public:
    int strStr(char *haystack, char *needle) {
		if(NULL == haystack || NULL == needle)
			return -1;

		int i = 0;
		int j = 0;

		while(haystack[i] != '\0'){
			if(haystack[i] == needle[0]){
				j = 0;
				int pos = i;
				while(haystack[i] != '\0' && needle[j] != '\0'){
					if(haystack[i] != needle[j])
						break;

					++j;
					++i;
				}

				if (needle[j] == '\0')
					return pos;
				else if (haystack[i] == '\0')
					return -1;

				i = pos+1;
			}else{
				++i;
			}
		}

		return (needle[j] == '\0') ? j : -1;
    }

	int strStr2(char *haystack, char *needle) {
		int m = strlen(needle);
		int* prefix = (int*)malloc(m*sizeof(int));
		int q = 0;
		const char * pCursor = needle;
		int i = 0;
		prefix[0] = 0;
		for(i = 1; i < m; ++i){
			// calc prefix arrry pi[i];
			if(needle[i] == *pCursor){
				prefix[i] = ++q;
				pCursor++;
			}else{
				q = 0;
				pCursor = needle;
			}
		}

		printArray<int>(prefix, m, "prefix");

		int n = strlen(haystack);
		q = 0;
		i = 0;
		while(i < n){
			if(haystack[i] == needle[q]){
				std::cout << "match q=" << q << "i=" << i << std::endl;
				++i;
				++q;
				if(q >= m)
					return i - m;
			}else{
				std::cout << "before q=" << q << "i=" << i << std::endl;
				while(haystack[i] != needle[q] && 0 != q){
					q = prefix[q - 1];
					std::cout << "q=" << q << std::endl;
				}

				if(0 == q)
					++i;
			}
		}

		return -1;
	}
};

int main(int argc, char** argv){
	if(argc < 3){
		printf("use %s haystack needle.\n", argv[0]);
		return 0;
	}

	Solution s;
	std::cout << s.strStr2(argv[1], argv[2]) << std::endl;
	return 0;
}
