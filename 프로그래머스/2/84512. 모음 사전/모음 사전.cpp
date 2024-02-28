#include <string>
#include <vector>

using namespace std;

int AlphaToNum(char ch)
{
    switch (ch) {
    case 'A': return 0;
    case 'E': return 1;
    case 'I': return 2;
    case 'O': return 3;
    case 'U': return 4;
    }
}

int solution(string word) {
    int answer = 0, t = 0;
    vector <char> v(5,'\0');
    for (int i = 0; i < word.size(); i++) v[i] = word[i];
    for (int i = 4; i >= 0; i--) {
        t = t * 5 + 1;
        if (v[i] != '\0') answer += t * AlphaToNum(v[i]) + 1;
    }
    
    return answer;
}