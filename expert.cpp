// #include<bits/stdc++.h>
// using namespace std;

// // Employee performance evaluation system



// int main(){
//     // we will consider factors like - productivity, attendance, teamwork, communication skills, problem-solving abilities, leadership skills
//     // most important - problem-solving abilities>leadership skills>attendance> communication skills>teamwork
//     // we will take input as a score out of 10 for each factor
//     // and based on the individual scores, we will calculate the overall score for each employee and rank them accordingly

//     int productivity=0;
//     int attendance=0;
//     int teamwork=0;
//     int communication_skills=0;
//     int problem_solving_abilities=0;
//     int leadership_skills=0;

//     int total_score=0;
//     cout<<"Enter employee name: ";
//     string name;
//     cin>>name;
//     cout<<"Enter problem-solving abilities score (out of 10): ";
//     cin>>problem_solving_abilities;
//     cout<<"Enter leadership skills score (out of 10): ";
//     cin>>leadership_skills;
//     cout<<"Enter attendance score (out of 10): ";
//     cin>>attendance;
//     cout<<"Enter communication skills score (out of 10): ";
//     cin>>communication_skills;
//     cout<<"Enter teamwork score (out of 10): ";
//     cin>>teamwork;
//     cout<<"Enter productivity score (out of 10): ";
//     cin>>productivity;

//     if(problem_solving_abilities>=8){
//         total_score+=40;
//         cout<<"Employee "<<name<<" is an expert in problem-solving abilities and has scored "<<problem_solving_abilities<<" out of 10 in this factor."<<endl;
//     }
//     else if(problem_solving_abilities>=6){
//         total_score+=30;
//     }
//     else if(problem_solving_abilities>=4){
//         total_score+=20;
//     }
//     else{
//         total_score+=10;
//     }

//     if(leadership_skills>=8){
//         total_score+=30;
//         cout<<"Employee "<<name<<" is an expert in leadership skills and has scored "<<leadership_skills<<" out of 10 in this factor."<<endl;
//     }
//     else if(leadership_skills>=6){
//         total_score+=20;
//     }
//     else if(leadership_skills>=4){
//         total_score+=10;
//     }
//     else{
//         total_score+=5;
//     }

//     if(attendance>=8){
//         total_score+=20;
//         cout<<"Employee "<<name<<" is punctual and has scored "<<attendance<<" out of 10 in this factor."<<endl;
//     }
//     else if(attendance>=6){
//         total_score+=15;
//     }
//     else if(attendance>=4){
//         total_score+=10;
//     }
//     else{
//         total_score+=5;
//     }
//     if(total_score>=80){
//         cout<<"Excellent performance !!"<<endl;
//         cout<<"Salary increment: 20%"<<endl;
//         cout<<"Bonus: 10%"<<endl;
//     }
//     else if(total_score>=60){
//         cout<<"Good performance !!"<<endl;
//         cout<<"Salary increment: 10%"<<endl;
//         cout<<"Bonus: 5%"<<endl;
//     }
//     else if(total_score>=40){
//         cout<<"Average performance !!"<<endl;
//         cout<<"Salary increment: 5%"<<endl;
//     }
//     else{
//         cout<<"Needs improvement !!"<<endl;
//     }
//     cout<<"Total score for employee "<<name<<" is: "<<total_score<<endl;

// }










#include<bits/stdc++.h>
using namespace std;

// Employee Performance Evaluation Expert System

int main(){
    // Factors (priority order):
    // problem-solving > leadership > attendance > communication > teamwork > productivity
    // Weights chosen accordingly (total = 100):
    //   problem-solving      : 25%
    //   leadership           : 20%
    //   attendance           : 17%
    //   communication        : 15%
    //   teamwork             : 12%
    //   productivity         : 11%
    // Each input is out of 10, so weighted_score = (input/10) * weight
    // Final total_score is out of 100.

    int productivity = 0;
    int attendance = 0;
    int teamwork = 0;
    int communication = 0;
    int problem_solving = 0;
    int leadership = 0;

    string name;
    cout << "============================================================\n";
    cout << "      EMPLOYEE PERFORMANCE EVALUATION - EXPERT SYSTEM       \n";
    cout << "============================================================\n";

    cout << "\nEnter employee name: ";
    cin >> name;

    cout << "\n--- Enter scores out of 10 for each factor ---\n";
    cout << "Problem-solving abilities (1-10): ";  cin >> problem_solving;
    cout << "Leadership skills         (1-10): ";  cin >> leadership;
    cout << "Attendance                (1-10): ";  cin >> attendance;
    cout << "Communication skills      (1-10): ";  cin >> communication;
    cout << "Teamwork                  (1-10): ";  cin >> teamwork;
    cout << "Productivity              (1-10): ";  cin >> productivity;

    // Weighted total — out of 100
    double total_score = (problem_solving * 2.5)
                       + (leadership      * 2.0)
                       + (attendance      * 1.7)
                       + (communication   * 1.5)
                       + (teamwork        * 1.2)
                       + (productivity    * 1.1);

    cout << "\n============================================================\n";
    cout << "                     INDIVIDUAL FEEDBACK                    \n";
    cout << "============================================================\n";

    // --- Problem-solving feedback ---
    cout << "\n[Problem-Solving]: ";
    if (problem_solving >= 8)
        cout << "Excellent! " << name << " is an expert problem-solver.";
    else if (problem_solving >= 6)
        cout << "Good analytical skills. Keep building on this strength.";
    else if (problem_solving >= 4)
        cout << "Average. Recommend training on critical thinking.";
    else
        cout << "Weak area. Needs structured problem-solving workshop.";

    // --- Leadership feedback ---
    cout << "\n[Leadership]: ";
    if (leadership >= 8)
        cout << "Outstanding leader. Consider for senior roles.";
    else if (leadership >= 6)
        cout << "Shows leadership potential. Mentor for team-lead role.";
    else if (leadership >= 4)
        cout << "Average leadership. Encourage taking ownership.";
    else
        cout << "Low leadership score. Assign leadership development plan.";

    // --- Attendance feedback ---
    cout << "\n[Attendance]: ";
    if (attendance >= 8)
        cout << "Punctual and regular. Reliable employee.";
    else if (attendance >= 6)
        cout << "Generally regular. Minor improvement needed.";
    else if (attendance >= 4)
        cout << "Inconsistent attendance. Counselling recommended.";
    else
        cout << "Poor attendance. Formal warning required.";

    // --- Communication feedback ---
    cout << "\n[Communication]: ";
    if (communication >= 8)
        cout << "Clear and effective communicator.";
    else if (communication >= 6)
        cout << "Decent communication skills.";
    else if (communication >= 4)
        cout << "Average. Recommend communication workshop.";
    else
        cout << "Weak communication. Soft-skills training needed.";

    // --- Teamwork feedback ---
    cout << "\n[Teamwork]: ";
    if (teamwork >= 8)
        cout << "Excellent team player.";
    else if (teamwork >= 6)
        cout << "Collaborates well with the team.";
    else if (teamwork >= 4)
        cout << "Average team integration. Could engage more.";
    else
        cout << "Struggles in teams. Pair with a mentor.";

    // --- Productivity feedback ---
    cout << "\n[Productivity]: ";
    if (productivity >= 8)
        cout << "Highly productive. Consistently meets/exceeds targets.";
    else if (productivity >= 6)
        cout << "Productive. Meets expectations.";
    else if (productivity >= 4)
        cout << "Below average. Set clearer goals.";
    else
        cout << "Low output. Place on performance improvement plan.";

    // --- Final report ---
    cout << "\n\n============================================================\n";
    cout << "                        FINAL REPORT                        \n";
    cout << "============================================================\n";
    cout << "Employee Name : " << name << "\n";
    cout << "Total Score   : " << fixed << setprecision(2)
         << total_score << " / 100\n";
    cout << "------------------------------------------------------------\n";

    if (total_score >= 85) {
        cout << "Rating        : OUTSTANDING\n";
        cout << "Salary Hike   : 25%\n";
        cout << "Bonus         : 15% of annual salary\n";
        cout << "Action        : Strongly recommend for promotion\n";
    }
    else if (total_score >= 70) {
        cout << "Rating        : EXCELLENT\n";
        cout << "Salary Hike   : 18%\n";
        cout << "Bonus         : 10% of annual salary\n";
        cout << "Action        : Eligible for promotion\n";
    }
    else if (total_score >= 55) {
        cout << "Rating        : GOOD\n";
        cout << "Salary Hike   : 10%\n";
        cout << "Bonus         : 5% of annual salary\n";
        cout << "Action        : Continue current role, encourage growth\n";
    }
    else if (total_score >= 40) {
        cout << "Rating        : AVERAGE\n";
        cout << "Salary Hike   : 5%\n";
        cout << "Bonus         : None\n";
        cout << "Action        : Recommend targeted training\n";
    }
    else {
        cout << "Rating        : NEEDS IMPROVEMENT\n";
        cout << "Salary Hike   : None\n";
        cout << "Bonus         : None\n";
        cout << "Action        : Place on Performance Improvement Plan (PIP)\n";
    }
    cout << "============================================================\n";

    return 0;
}
