#include <iostream>
#include <unordered_map>
#include <limits>

#define slash '/'
#define star '*'
#define character 'a'
#define print(x) std::cout << x << std::endl

enum state{
    A, 
    B,
    C,
    D,
    E
};
//hash overload for enum state
struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};
//dynamic message retrieval
std::unordered_map<state, std::string, EnumClassHash> messageMap = {
    {A, "['/' = /, '*' = *, 'a' = a, 'q' = quit]"},
    {B, "['/' = /, '*' = *, 'a' = a, 'q' = quit]"},
    {C, "['/' = /, '*' = *, 'a' = a, 'q' = quit]"},
    {D, "['/' = /, '*' = *, 'a' = a, 'q' = quit]"},
    {E, "['/' = /, '*' = *, 'a' = a, 'q' = quit]"}
};

//Q = state input, c = char input, cState = choose the state for c for multiple paths
state transition(state Q, char c = '\0'){
    switch(Q){
        case A:
            return c == '/'? B : E;
            break;
        case B:
            return c == '*'? C : E;
            break;
        case C:
            if(c == 'a')
                return C;
            else if(c == '*')
                return D;
            else 
                return E;
            break;
        case D:
            if(c == 'a')
                return C;
            else if(c == '*')
                return D;
            else 
                return E;
            break;
        case E:
            return E;
            break;
        default:
            print("something went wrong");
            exit(-1);
    }
}

void eventLoop(){
    std::string charArray = "";
    std::string outArray = "";
    char input = '\0';

    state currentState = A;

    while(true){

        std::cout << "\nenter your input " << messageMap[currentState] << ":" << std::endl;
        std::cin >> input;

        if(input == 'q')
            break;

        // if(std::isdigit(input)){
        //     int castedIn = input-'0';

        //     switch(castedIn){
        //         case 5:
        //             if(currentState == Q4)
        //                 charArray.push_back('a');
        //             else if(currentState == Q5)
        //                 charArray.push_back('*');
        //             break;
        //         case 3: 
        //             charArray.push_back('a');
        //             break;
        //         case 2: 
        //             charArray.push_back('a');
        //             break;
        //         case 4:
        //             charArray.push_back('a');
        //             break;
        //         case 6:
        //             charArray.push_back('*');
        //             break;
        //         default:
        //             print("input not in range");
        //             exit(-1);
        //     }
        //     currentState = transition(currentState, NULL, input-'0');
        // }

        if(input == '/' && currentState == D) {
            outArray.push_back('1');
        }
        else {
            outArray.push_back('0');
        }

        currentState = transition(currentState, input);
        charArray.push_back(input);

        std::cout << "your current string is: " << charArray << '\n';
        std::cout << "output is: " << outArray << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main(){

    eventLoop();
    
}