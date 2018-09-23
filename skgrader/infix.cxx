#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//Only single digit numbers permitted

int GetPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    default:
        return 2;
    }
}
char* ConvertInorderToPreOrder(char* InOrderExp, int Size)
{
    stack<char> Operators;
    vector<char> PostOrderResult;
    for (int i = Size-1; i >=0; i--)
        if (InOrderExp[i] >= '0'&& InOrderExp[i] <= '9')
            PostOrderResult.push_back(InOrderExp[i]);
        else
        {
            while (!Operators.empty() && GetPrecedence(Operators.top()) >= GetPrecedence(InOrderExp[i]))
            {
                PostOrderResult.push_back(Operators.top());
                Operators.pop();
            }
            Operators.push(InOrderExp[i]);
        }
    while (!Operators.empty())
    {
        PostOrderResult.push_back(Operators.top());
        Operators.pop();
    }
    char *ResultString = (char*)malloc(sizeof(char)*PostOrderResult.size()+1);
    memset(ResultString, 0, sizeof(char)*(PostOrderResult.size() + 1));
    for (int i = 0; i < PostOrderResult.size(); i++)
        ResultString[i] = PostOrderResult[i];
    ResultString[PostOrderResult.size()] = '\0';
    _strrev(ResultString);
    return ResultString;
}
char* ConvertInorderToPostOrder(char* InOrderExp, int Size)
{
    stack<char> Operators;
    vector<char> PostOrderResult;
    for (int i = 0; i < Size; i++)
        if (InOrderExp[i] >= '0'&& InOrderExp[i] <= '9')
            PostOrderResult.push_back(InOrderExp[i]);
        else
        {
            while (!Operators.empty() && GetPrecedence(Operators.top()) >= GetPrecedence(InOrderExp[i]))
            {
                PostOrderResult.push_back(Operators.top());
                Operators.pop();
            }
            Operators.push(InOrderExp[i]);
        }
    while (!Operators.empty())
    {
        PostOrderResult.push_back(Operators.top());
        Operators.pop();
    }
    char *ResultString = (char*)malloc(sizeof(char)*PostOrderResult.size()+1);
    memset(ResultString, 0, sizeof(char)*(PostOrderResult.size()+1));
    for (int i = 0; i < PostOrderResult.size(); i++)
        ResultString[i] = PostOrderResult[i];
    ResultString[PostOrderResult.size()] = '\0';
    return ResultString;
}

int main()
{

    char InExp[] = "2+3*7-5*2-4/2*5+1-4+2/2+1";
    cout << "\nInput: " << InExp;
    cout << "\n\n";
    cout << "\n\PostFix = " << ConvertInorderToPostOrder(InExp, strlen(InExp));
    cout << "\n\PreFix = " << ConvertInorderToPreOrder(InExp, strlen(InExp));
    cout << "\n\nEnd of code\n\n";
    system("pause");
    return 0;
}
