#include <iostream>
using namespace std;

class Triad{
public:
    int first_triad[3], second_triad[3];
    
    void output_triad(int a[3], int b[3], short int c){
        if(c==0){
            for(int i=0; i<3; i++){
                if(i==0){
                    cout<<"(";
                }
                if(i!=2){
                    cout<<a[i]<<",";
                } else{
                    cout<<a[i]<<")  ";
                }
            };
            for(int i=0; i<3; i++){
                if(i==0){
                    cout<<"(";
                }
                if(i!=2){
                    cout<<b[i]<<",";
                } else{
                    cout<<b[i]<<") ";
                }
            };
        } else{
            for(int i=0; i<3; i++){
                if(i==0){
                    cout<<"{";
                }
                if(i!=2){
                    cout<<a[i]<<":";
                } else{
                    cout<<a[i]<<"}  ";
                }
            };
            for(int i=0; i<3; i++){
                if(i==0){
                    cout<<"{";
                }
                if(i!=2){
                    cout<<b[i]<<":";
                } else{
                    cout<<b[i]<<"} ";
                }
            };
        }
    }
    void compare_triad(int a[3], int b[3]){
        if(((a[0]>b[0]) or ((a[0]==b[0]) and (a[1]>b[1]) )) or ((a[0]==b[0]) and (a[1]==b[1]) and (a[2]>b[2]))){
            cout<<"great"<<endl;
        } else if((a[0]==b[0]) and (a[1]==b[1]) and (a[2]==b[2])){
            cout<<"equal"<<endl;
        } else{
            cout<<"less"<<endl;
        };
    };
    
};
class Time: public Triad{
public:
    int first_time[3], second_time[3];
    
    void Read() {
        for(int i=0; i<3; i++){
            cin>>first_triad[i];
        };
        for(int i=0; i<3; i++){
            cin>>second_triad[i];
        };
        for(int i=0; i<3; i++){
            cin>>first_time[i];
        };
        for(int i=0; i<3; i++){
            cin>>second_time[i];
        };
    }
    int is_it_time(int a[3], int b[3]){
        if(a[0]<24 and a[0]>0 and a[1]<60 and a[1]>0 and a[2]<60 and a[2]>0){
            if(b[0]<24 and b[0]>0 and b[1]<60 and b[1]>0 and b[2]<60 and b[2]>0){
                return 1;
            } else{
                return 0;
            }
        } else{
            return 0;
        }
    }
    void change(){
        short int change_number;
        int changing;
        while(cin>>change_number and change_number!=0){
            switch(change_number){
                case 1: cin>>changing;
                    first_triad[0] = changing;
                    output_triad(first_triad, second_triad, 0);
                    compare_triad(first_triad, second_triad);
                    break;
                case 2: cin>>changing;
                    first_triad[1] = changing;
                    output_triad(first_triad, second_triad, 0);
                    compare_triad(first_triad, second_triad);
                    break;
                case 3: cin>>changing;
                    first_triad[2] = changing;
                    output_triad(first_triad, second_triad, 0);
                    compare_triad(first_triad, second_triad);
                    break;
                case 4: cin >> changing;
                    second_triad[0] = changing;
                    output_triad(first_triad, second_triad, 0);
                    compare_triad(first_triad, second_triad);
                    break;
                case 5: cin >> changing;
                    second_triad[1] = changing;
                    output_triad(first_triad, second_triad, 0);
                    compare_triad(first_triad, second_triad);
                    break;
                case 6: cin >> changing;
                    second_triad[2] = changing;
                    output_triad(first_triad, second_triad, 0);
                    compare_triad(first_triad, second_triad);
                    break;
                case 7: cin >> changing;
                    first_time[0] = changing;
                    output_triad(first_time, second_time, 1);
                    if(is_it_time(first_time, second_time)){
                        compare_triad(first_time, second_time);    
                    }else{
                        cout<<"not time"<<endl;
                    }
                    break;
                case 8: cin >> changing;
                    first_time[1] = changing;
                    output_triad(first_time, second_time, 1);
                    if(is_it_time(first_time, second_time)){
                        compare_triad(first_time, second_time);    
                    }else{
                        cout<<"not time"<<endl;
                    }
                    break;
                case 9: cin >> changing;
                    first_time[2] = changing;
                    output_triad(first_time, second_time, 1);
                    if(is_it_time(first_time, second_time)){
                        compare_triad(first_time, second_time);    
                    }else{
                        cout<<"not time"<<endl;
                    }
                    break;
                case 10: cin >> changing;
                    second_time[0] = changing;
                    output_triad(first_time, second_time, 1);
                    if(is_it_time(first_time, second_time)){
                        compare_triad(first_time, second_time);    
                    }else{
                        cout<<"not time"<<endl;
                    }
                    break;
                case 11: cin >> changing;
                    second_time[1] = changing;
                    output_triad(first_time, second_time, 1);
                    if(is_it_time(first_time, second_time)){
                        compare_triad(first_time, second_time);    
                    }else{
                        cout<<"not time"<<endl;
                    }
                    break;
                case 12: cin >> changing;
                    second_time[2] = changing;
                    output_triad(first_time, second_time, 1);
                    if(is_it_time(first_time, second_time)){
                        compare_triad(first_time, second_time);    
                    }else{
                        cout<<"not time"<<endl;
                    }
                    break;
            }
        }
    }
    void Display(){
        output_triad(first_triad, second_triad, 0);
        compare_triad(first_triad, second_triad);
        output_triad(first_time, second_time, 1);
        if(is_it_time(first_time, second_time)){
            compare_triad(first_time, second_time);
        };
        change();
    }
};
int main(){
    Triad three;
    Time date;
    date.Read();
    date.Display();
}
