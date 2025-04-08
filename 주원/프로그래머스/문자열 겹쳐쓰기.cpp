#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    my_string.replace(s,overwrite_string.size(),overwrite_string);
    //문자열 시작 길이, 문자열 끝 길이, 바꿀 문자열
    return my_string;
}