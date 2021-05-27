#include<iostream>
#include<windows.h>
#include<ctime>
#include<algorithm>
using namespace std;
class game
{
    private:
        short int bunker=-1,bombed_bunker[3],count=0;
        string bunkers_left[4]={"Bunker Alpha","Bunker Bravo","Bunker Clay","Bunker Delta"};
        void radio_static_text(string str)
        {
            system("cls");
            cout<<"*Radio static*";
            Sleep(2000);
            system("cls");
            for (int i = 0; i < str.size(); i++)
            {
                cout<<str[i]<<flush;
                Sleep(100);
            }            
            Sleep(2500);
        }
    public:
        game()
        {
            system("cls");
            cout<<"\033[34;1mBunker Hunt\033[0m\nPress enter to start";
            cin.get();
            system("cls");
            radio_static_text("If you have received this message...");
            radio_static_text("Get... to a... bunker immediately...");
            radio_static_text("...world is under attack...extraterrestrials");
            system("cls");
            cout<<"You pack up your survival supplies and head towards the nearest bunker\n";
            cout<<"4 Bunkers remain:\n";
            check_bunkers();
        }
        game &take_input()
        {
            string bunker;
            while(this->bunker==-1)
            {
            getline(cin,bunker);
            transform(bunker.begin(),bunker.end(),bunker.begin(),::tolower);
            if(bunker=="alpha"||bunker=="bunker alpha")
                this->bunker=0;
            else if(bunker=="bravo"||bunker=="bunker bravo")
                this->bunker=1;
            else if(bunker=="clay"||bunker=="bunker clay")
                this->bunker=2;
            else if(bunker=="delta"||bunker=="bunker delta")
                this->bunker=3;
            else
                {
                    cout<<"Enter the name of the bunker you wish to go to";
                    Sleep(2000);
                    system("cls");
                    check_bunkers();
                }              
            }            
            return *this;
        }
        game &bombing()
        {
            system("cls");
            cout<<"Oh no, the extraterrestrials have found the bunkers!\nThey are going to destroy one of them. Pray it isn't yours!";
            Sleep(4000);
            system("cls");
            cout<<"Attack under way";
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
            bombed_bunker[count]=rand()%(4);
            for(int i=0;i<count;i++)
            {
                if(bombed_bunker[i]==bombed_bunker[count])
                    while (bombed_bunker[i]==bombed_bunker[count])
                    {
                        bombed_bunker[count]=rand()%4;
                    }                    
            }
            bunkers_left[bombed_bunker[count]]="     X";
            return *this;           
        }
        game &declare_result()
        {
            if(bunker==bombed_bunker[count])
            {
                cout<<"The aliens destroyed your bunker :(\n\033[31;1mGAME OVER\033[0m\n\n\nPress enter to exit";
                cin.get();
                exit(0);
            }
            else if(count==2)
            {
                system("cls");
                cout<<"You survived!\nThe extraterrestrials go away as mysteriously as they came\nEverything you once knew is destroyed. But hey, you're still alive right?\n";
                cout<<"You and the other survivors start rebuilding Earth\n";
                cout<<"**Press enter to exit**";
                cin.get();
                system("cls");
                cout<<"\033[31;1mVENGENCE SHALL BE OURS\033[0m";
                Sleep(500);
                system("cls");
                cout<<"\033[1mMade by Aphievel\033[0m";
                Sleep(4000);
                exit(0);
            }
            else
            {
                cout<<"You survived! Now choose which bunker you will go to?\n";
                count++;
                bunker=-1;
                check_bunkers();
            }
            return *this;
        }
        game &check_bunkers()
        {
            for(string i:bunkers_left)
                cout<<i<<"\n";
            return *this;
        }
        bool is_over()
        {
            return count!=3;
        }
};

int main()
{
    game g;
    while (g.is_over())
    {
        g.take_input().bombing().declare_result();
    }   
}