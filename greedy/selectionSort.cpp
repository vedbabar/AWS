#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<pair<string,int>> students = {

    {"Student1",78},
    {"Student2",92},
    {"Student3",85},
    {"Student4",95},
    {"Student5",88},
    {"Student6",67},
    {"Student7",74},
    {"Student8",81},
    {"Student9",90},
    {"Student10",56},

    {"Student11",69},
    {"Student12",73},
    {"Student13",84},
    {"Student14",91},
    {"Student15",77},
    {"Student16",65},
    {"Student17",88},
    {"Student18",93},
    {"Student19",79},
    {"Student20",82},

    {"Student21",71},
    {"Student22",64},
    {"Student23",89},
    {"Student24",94},
    {"Student25",58},
    {"Student26",76},
    {"Student27",83},
    {"Student28",68},
    {"Student29",87},
    {"Student30",92},

    {"Student31",55},
    {"Student32",72},
    {"Student33",80},
    {"Student34",97},
    {"Student35",66},
    {"Student36",75},
    {"Student37",84},
    {"Student38",91},
    {"Student39",78},
    {"Student40",86},

    {"Student41",63},
    {"Student42",74},
    {"Student43",88},
    {"Student44",95},
    {"Student45",69},
    {"Student46",77},
    {"Student47",82},
    {"Student48",90},
    {"Student49",61},
    {"Student50",73},

    {"Student51",85},
    {"Student52",92},
    {"Student53",79},
    {"Student54",67},
    {"Student55",81},
    {"Student56",94},
    {"Student57",76},
    {"Student58",88},
    {"Student59",70},
    {"Student60",83},

    {"Student61",65},
    {"Student62",91},
    {"Student63",74},
    {"Student64",87},
    {"Student65",93},
    {"Student66",58},
    {"Student67",72},
    {"Student68",84},
    {"Student69",96},
    {"Student70",77},

    {"Student71",69},
    {"Student72",80},
    {"Student73",92},
    {"Student74",73},
    {"Student75",85},
    {"Student76",64},
    {"Student77",78},
    {"Student78",89},
    {"Student79",95},
    {"Student80",66},

    {"Student81",71},
    {"Student82",83},
    {"Student83",90},
    {"Student84",75},
    {"Student85",87},
    {"Student86",62},
    {"Student87",94},
    {"Student88",79},
    {"Student89",68},
    {"Student90",81},

    {"Student91",76},
    {"Student92",88},
    {"Student93",97},
    {"Student94",72},
    {"Student95",84},
    {"Student96",65},
    {"Student97",91},
    {"Student98",78},
    {"Student99",86},
    {"Student100",93}
};

    int k = 3;

    for(int i=0;i<k;i++){

        int maxi = i;

        for(int j=i+1;j<students.size();j++){

            if(students[j].second >
               students[maxi].second){

                maxi = j;
            }
        }

        swap(students[i], students[maxi]);
    }

    cout<<"Top "<<k<<" Students:"<<endl;

    for(int i=0;i<k;i++){

        cout<<students[i].first
            <<" "
            <<students[i].second
            <<endl;
    }
}