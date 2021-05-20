#include<iostream>
#include<windows.h>
#include<ctime>
using namespace std;
class game
{
    private:
        short int city=-1,bombed_city;
    public:
        game()
        {
            system("cls");
            cout<<"Welcome to bombing the city game\nPress enter to start\n";
            cin.get();
            system("cls");
            cout<<"Aliens have invaded earth!\nThe survivors are hiding in 4 cities\nThe aliens will bomb one of the 4 cities\nChoose which city you want to hide in\n";
            cout<<" Washington DC   Delhi\n Seoul           Tokyo\n";
        }
        game &take_input()
        {
            string city;
            while(this->city==-1)
            {
            getline(cin,city);
            if(city=="Washington DC")
                this->city=0;
            else if(city=="Delhi")
                this->city=1;
            else if(city=="Seoul")
                this->city=2;
            else if(city=="Tokyo")
                this->city=3;
            else
                {
                    cout<<"Only 4 cities are left. Choose one of them.";
                    Sleep(1000);
                    system("cls");
                    cout<<"Aliens have invaded earth!\nThe survivors are hiding in 4 cities\nThe aliens will bomb one of the 4 cities\nChoose which city you want to hide in\n";
                    cout<<" Washington DC   Delhi\n Seoul           Tokyo\n";
                }              
            }            
            return *this;
        }
        game &bombing()
        {
            system("cls");
            cout<<"Bombing taking place";
            for (int j = 0; j < 3; j++)
            {
                for (int i = 0; i < 3; i++)
                {
                    Sleep(400);
                    cout<<".";
                }
                Sleep(400);
                cout<<"\b\b\b   \b\b\b";
            } 
            system("cls");
            srand(time(0));
            bombed_city=rand()%4;
            cout<<bombed_city<<" "<<city;
            return *this;           
        }
        game &declare_result()
        {
            if(city==bombed_city)
                cout<<"The aliens bombed your city :(";
            else cout<<"You survived!";
            return *this;
        }
};

int main()
{
    game g;
    g.take_input().bombing().declare_result();
}