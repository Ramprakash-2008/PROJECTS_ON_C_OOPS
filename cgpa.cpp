#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class CGPA{
    string a,b,c,d,e,f,g,h,i;
    static double cumulativeGradePoints;
    static int cumulativeCredits;
    public:
    CGPA(int year, int semester){
       
        if(!(year==1 && semester==1) ){
            cout<<"Non-first semester detected.\nIf you have a previous overall CGPA, enter it now (enter 0 if none): ";
            double prevCGPA = 0.0; int prevCredits = 0;
            cin>>prevCGPA;
            cout<<"Enter total credits completed before this semester: ";
            cin>>prevCredits;
            cumulativeCredits = prevCredits;
            cumulativeGradePoints = prevCGPA * prevCredits;
        }
        if(year==1 && semester==1){
           firstYearFirstSemester();    
        }
        else if(year==1 && semester==2){
            firstYearSecondSemester();
        }
        else if(year==2 && semester==1){
            secondYearFirstSemester();
        }
        else if(year==2 && semester==2){
            secondYearSecondSemester();
        }
        else if(year==3 && semester==1){
            thirdYearFirstSemester();
        }
        else if(year==3 && semester==2){
            thirdYearSecondSemester();
        }
        else if(year==4 && semester==1){
        fourthYearFirstSemester();
        }
        else if(year==4 && semester==2){
        fourthyearsecondSemester();
        }
         else{
            cout<<"Invalid input!";
         }
          cout<<"Returning to main for next input."<<endl;
    }

    int cgpaGradetomark(string grade)
    {
        unordered_map<string,int> gp =
        {
            {"S",10},
            {"A+",9},
            {"A",8},
            {"B+",7},
            {"B",6},
            {"C",5},
            {"RA",0}
        };

        return gp.count(grade) ? gp[grade] : -1;
    }
    string readGradeNoPrompt(){
        string g;
        while(true){
            if(!(cin>>g)){
                cin.clear();
                string dummy; getline(cin,dummy);
                cout<<"Invalid input. Try again: ";
                continue;
            }
            string up;
            for(char ch: g) up += toupper((unsigned char)ch);
            if(up=="U" || up=="RA/U") up = "RA";
            if(up=="RA"){
                return up;
            }
            if(up=="S" || up=="A+" || up=="A" || up=="B+" || up=="B" || up=="C"){
                return up;
            }
            cout<<"Wrong input. Try again. ENTER YOUR GRADE : ";
        }
    }
    void firstYearFirstSemester(){
        cout<<"First Year First Semester CGPA Calculator !! "<<endl;
        int FE=3, MC=4, EP=4, FEEE=3, PC=4, CT=2, HT=1;
        cout<<"EN23CO1-FOUNDATION ENGLISH \nENTER YOUR GRADE : ";
        a = readGradeNoPrompt();
        cout<<"MA23CO1-MATRICES AND CALCULUS \nENTER YOUR GRADE : ";
        b = readGradeNoPrompt();
        cout<<"PH23CO1-ENGINEERING PHYSICS \nENTER YOUR GRADE : ";
        c = readGradeNoPrompt();
        cout<<"EE23CO1-FUNDAMENTALS OF ELECTRICAL AND ELECTRONICS ENGINEERING \nENTER YOUR GRADE : ";
        d = readGradeNoPrompt();
        cout<<"CS23CO4-PROGRAMMING IN C \nENTER YOUR GRADE : ";
        e = readGradeNoPrompt();
        cout<<"CS231O1-COMPUTATIONAL THINKING \nENTER YOUR GRADE : ";
        f = readGradeNoPrompt();
        cout<<"UC23H01-HERITAGE OF TAMIL \nENTER YOUR GRADE : ";
        g = readGradeNoPrompt();
            int totalCredits=FE+MC+EP+FEEE+PC+CT+HT;
            int totalMarks=cgpaGradetomark(a)*FE + cgpaGradetomark(b)*MC + cgpaGradetomark(c)*EP + cgpaGradetomark(d)*FEEE + cgpaGradetomark(e)*PC + cgpaGradetomark(f)*CT + cgpaGradetomark(g)*HT;
            float cgpa=(float)totalMarks/totalCredits;
            cumulativeCredits += totalCredits;
            cumulativeGradePoints += totalMarks;
            auto overallCGPA = (float)cumulativeGradePoints / cumulativeCredits;
            cout << "Semester GPA : " << cgpa << endl;
            cout << "Overall CGPA : " << overallCGPA << endl;
            cout<<"No. of backlogs : ";
            int backlog = 0;
        vector<string> grades = {a,b,c,d,e,f,g};
        for (const auto &grade : grades) if(cgpaGradetomark(grade)==0) ++backlog;
            cout<<backlog<<endl;
    }           
    void firstYearSecondSemester(){
        cout<<"First Year Second Semester CGPA Calculator !! "<<endl;
        int PE=3, DM=4, EC=4, ED=4, MS=3, TT=1, OOP=3;  
        cout<<"EN23CO2-PROFESSIONAL ENGLISH \nENTER YOUR GRADE : ";
        a = readGradeNoPrompt();
        cout<<"MA23C02-DISCRETE MATHEMATICS \nENTER YOUR GRADE : ";
        b = readGradeNoPrompt(); 
        cout<<"CY23CO1-ENGINEERING CHEMISTRY \nENTER YOUR GRADE : ";
        c = readGradeNoPrompt();
        cout<<"ME23C01-ENGINEERING DRAWING \nENTER YOUR GRADE : ";
        d = readGradeNoPrompt();
        cout<<"ME23CO4-MAKERSPACE \nENTER YOUR GRADE : ";
        e = readGradeNoPrompt();
        cout<<"UC23H02-TAMIL AND TECHNOLOGY\nENTER YOUR GRADE : ";
        f = readGradeNoPrompt();
        cout<<"OBJECT ORIENTED PROGRAMMING USING C++ \nENTER YOUR GRADE : ";
        g = readGradeNoPrompt(); 
        int totalCredits=PE+DM+EC+ED+MS+TT+OOP;
        int totalMarks=cgpaGradetomark(a)*PE + cgpaGradetomark(b)*DM + cgpaGradetomark(c)*EC + cgpaGradetomark(d)*ED + cgpaGradetomark(e)*MS + cgpaGradetomark(f)*TT + cgpaGradetomark(g)*OOP;
        float cgpa=(float)totalMarks/totalCredits;   
        cumulativeCredits += totalCredits;
        cumulativeGradePoints += totalMarks;
        auto overallCGPA = (float)cumulativeGradePoints / cumulativeCredits;
        cout << "Semester GPA : " << cgpa << endl;
        cout << "Overall CGPA : " << overallCGPA << endl;
        cout<<"No. of backlogs : ";
        int backlog = 0;
        vector<string> grades = {a,b,c,d,e,f,g};
        for (const auto &grade : grades) if(cgpaGradetomark(grade)==0) ++backlog;
        cout<<backlog<<endl;
    }
    void secondYearFirstSemester(){
        cout<<"Second Year First Semester CGPA Calculator !! "<<endl;
        int PS=4, DS=5, DSD=5, JP=5, SE=3, SCE=1, UHV=2, SDC=2;
        cout<<"MA23CO5 - PROBABILITY AND STATISTICS \nENTER YOUR GRADE : ";
        a = readGradeNoPrompt(); 
        cout<<"CS23301-SOFTWARE ENGINEERING \nENTER YOUR GRADE : ";
        b = readGradeNoPrompt();
        cout<<"CS23302-DATA STRUCTURES \nENTER YOUR GRADE : ";
        c = readGradeNoPrompt(); 
        cout<<"CS23303-DIGITAL SYSTEM DESIGN \nENTER YOUR GRADE : ";
        d = readGradeNoPrompt();
        cout<<"CS23304-JAVA PROGRAMMING \nENTER YOUR GRADE : ";
        e = readGradeNoPrompt(); 
        cout<<"CS23U01-STANDARDS -COMPUTER SCIENCE &ENGINEERING \nENTER YOUR GRADE : ";
        f = readGradeNoPrompt();
        cout<<"UC23U01-UNIVERSAL HUMAN VALUES \nENTER YOUR GRADE : ";
        g = readGradeNoPrompt();
        cout<<"Skill development course-1 \nENTER YOUR GRADE : ";
        h = readGradeNoPrompt(); 
        int totalCredits=PS+DS+DSD+JP+SE+SCE+UHV+SDC;
        int totalMarks=cgpaGradetomark(a)*PS + cgpaGradetomark(b)*DS + cgpaGradetomark(c)*DSD + cgpaGradetomark(d)*JP + cgpaGradetomark(e)*SE + cgpaGradetomark(f)*SCE + cgpaGradetomark(g)*UHV + cgpaGradetomark(h)*SDC;
        float cgpa=(float)totalMarks/totalCredits;  
        cumulativeCredits += totalCredits;
        cumulativeGradePoints += totalMarks;
        auto overallCGPA = (float)cumulativeGradePoints / cumulativeCredits;
        cout << "Semester GPA : " << cgpa << endl;
        cout << "Overall CGPA : " << overallCGPA << endl;
        cout<<"No. of backlogs : ";
        int backlog = 0;
        vector<string> grades = {a,b,c,d,e,f,g,h};
        for (const auto &grade : grades) if(cgpaGradetomark(grade)==0) ++backlog;
        cout<<backlog<<endl;
    }
    void secondYearSecondSemester(){
        cout<<"Second Year Second Semester CGPA Calculator !! "<<endl;
        int LA=4, DBMS=5, CA=4, FST=4, DAA=3, SDC2=2, IOC=1;
        cout<<"MA23CO3-LINEAR ALGEBRA AND NUMERICAL METHODS \nENTER YOUR GRADE : ";
        a = readGradeNoPrompt();
        cout<<"CS23401-DATABASE MANAGEMENT SYSTEMS \nENTER YOUR GRADE : ";
        b = readGradeNoPrompt();
        cout<<"CS23402-COMPUTER ARCHITECTURE \nENTER YOUR GRADE : ";
        c = readGradeNoPrompt();
        cout<<"CS23403-FULL STACK TECHNOLOGIES \nENTER YOUR GRADE : ";
        d = readGradeNoPrompt();
        cout<<"CS23404-DESIGN AND ANALYSIS OF ALGORITHMS \nENTER YOUR GRADE : ";
        e = readGradeNoPrompt();
        cout<<"Skill development course-2 \nENTER YOUR GRADE : ";
        f = readGradeNoPrompt();
        cout<<"Industry oriented course \nENTER YOUR GRADE : ";
        g = readGradeNoPrompt();
        int totalCredits=LA+DBMS+CA+FST+DAA+SDC2+IOC;
        int totalMarks=cgpaGradetomark(a)*LA + cgpaGradetomark(b)*DBMS + cgpaGradetomark(c)*CA + cgpaGradetomark(d)*FST + cgpaGradetomark(e)*DAA + cgpaGradetomark(f)*SDC2 + cgpaGradetomark(g)*IOC;
        float cgpa=(float)totalMarks/totalCredits;      
        cumulativeCredits += totalCredits;
        cumulativeGradePoints += totalMarks;
        auto overallCGPA = (float)cumulativeGradePoints / cumulativeCredits;
        cout << "Semester GPA : " << cgpa << endl;
        cout << "Overall CGPA : " << overallCGPA << endl;
        cout<<"No. of backlogs : ";
        int backlog = 0;
        vector<string> grades = {a,b,c,d,e,f,g};
        for (const auto &grade : grades) if(cgpaGradetomark(grade)==0) ++backlog;
        cout<<backlog<<endl;

    }
    void thirdYearFirstSemester(){
        cout<<"Third Year First Semester CGPA Calculator !! "<<endl;
        int OS=5, NDCC=5, TOC=3, PE1=3, OE1=3, SLC=1, IOC2=1, EED=3, SDC3=2;
        cout<<"CS23501-OPERATING SYSTEMS \nENTER YOUR GRADE : ";
        a = readGradeNoPrompt();
        cout<<"CS23502-NETWORKS AND DATA COMMUNICATION \nENTER YOUR GRADE : ";
        b = readGradeNoPrompt();
        cout<<"CS23503-THEORY OF COMPUTATION \nENTER YOUR GRADE : ";    
        c = readGradeNoPrompt();
        cout<<"PROFESSIONAL ELECTIVE-1 \nENTER YOUR GRADE : ";
        d = readGradeNoPrompt();
        cout<<"OPEN ELECTIVE-1 \nENTER YOUR GRADE : ";
        e = readGradeNoPrompt();
        cout<<"CS23L01--SELF LEARNING COURSE \nENTER YOUR GRADE : "; 
        f = readGradeNoPrompt();
        cout<<"INDUSTRY ORIENTED COURSE-2 \nENTER YOUR GRADE : ";
        g = readGradeNoPrompt();
        cout<<"ENGINEERING ENTREPRENEURSHIP DEVELOPMENT \nENTER YOUR GRADE : ";
        h = readGradeNoPrompt();
        cout<<"SKILL DEVELOPMENT COURSE-3 \nENTER YOUR GRADE : ";
        i = readGradeNoPrompt(); 
        int totalCredits=OS+NDCC+TOC+PE1+OE1+SLC+IOC2+EED+SDC3;
        int totalMarks=cgpaGradetomark(a)*OS + cgpaGradetomark(b)*NDCC + cgpaGradetomark(c)*TOC + cgpaGradetomark(d)*PE1 + cgpaGradetomark(e)*OE1 + cgpaGradetomark(f)*SLC + cgpaGradetomark(g)*IOC2 + cgpaGradetomark(h)*EED + cgpaGradetomark(i)*SDC3;
        float cgpa=(float)totalMarks/totalCredits;   
        cumulativeCredits += totalCredits;
        cumulativeGradePoints += totalMarks;
        auto overallCGPA = (float)cumulativeGradePoints / cumulativeCredits;
        cout << "Semester GPA : " << cgpa << endl;
        cout << "Overall CGPA : " << overallCGPA << endl;
        cout<<"No. of backlogs : ";
        int backlog = 0;
        vector<string> grades = {a,b,c,d,e,f,g,h,i};
        for (const auto &grade : grades) if(cgpaGradetomark(grade)==0) ++backlog;
        cout<<backlog<<endl; 
        cout<<"COURSE FOR HONOURS DEGREE \nENTER YOUR  TYPE(1/2) : ";int type;
        cin>>type;
        if(type==1){
        string honoursGrade;
        cout<<"Enter your grade for honours course(CS23D01-CAPSTONE-IDEALTION) : ";
        cin>>honoursGrade;
        int  honoursCredits=6;  
        int honoursMarks=cgpaGradetomark(honoursGrade)*honoursCredits;
        float honoursCGPA=(float)honoursMarks/honoursCredits;       
        cout<<"Your Honours CGPA is : "<<honoursCGPA<<endl;
        }
            else if(type==2){
                string he1,he2;
                cout<<"Enter your grade for honours elective-1 : ";cin>>he1;
                cout<<"Enter your grade for honours elective-2 : ";cin>>he2;    
                int honoursCredits=3+3;
                int honoursMarks=cgpaGradetomark(he1)*3 + cgpaGradetomark(he2)*3;
                float honoursCGPA=(float)honoursMarks/honoursCredits;   
                cout<<"Your Honours CGPA is : "<<honoursCGPA<<endl;
            }
             else{
                cout<<"Invalid input for honours degree type!"<<endl;
            }
                

    }
    void thirdYearSecondSemester(){
        cout<<"Third Year Second Semester CGPA Calculator !! "<<endl;
        int CNS=4, CD=4,ML=5, PE2=3, OE2=3, PE3=3, PSD=3, CIP=2;
        cout<<"CS23601-CRYTPTOGRAPHY AND NETWORK SECURITY \nENTER YOUR GRADE : ";
        a = readGradeNoPrompt();
        cout<<"CS23602-COMPILER DESIGN \nENTER YOUR GRADE : ";
        b = readGradeNoPrompt();
        cout<<"CS23603-MACHINE LEARNING \nENTER YOUR GRADE : ";
        c = readGradeNoPrompt(); 
        cout<<"PROFESSIONAL ELECTIVE-2 \nENTER YOUR GRADE : ";
        d = readGradeNoPrompt();
        cout<<"OPEN ELECTIVE-2 \nENTER YOUR GRADE : ";
        e = readGradeNoPrompt();
        cout<<"PROFESSIONAL ELECTIVE-3 \nENTER YOUR GRADE : ";
        f = readGradeNoPrompt();
        cout<<"CS23U02-PERSPETIVES OF SUSTAINABLE DEVELOPMENT \nENTER YOUR GRADE : ";
        g = readGradeNoPrompt();
        cout<<"CREATIVE AND INNOVATIVE PROJECT \nENTER YOUR GRADE : ";
        h = readGradeNoPrompt();
        int totalCredits=CNS+CD+ML+PE2+OE2+PE3+PSD+CIP;
        int totalMarks=cgpaGradetomark(a)*CNS + cgpaGradetomark(b)*CD + cgpaGradetomark(c)*ML + cgpaGradetomark(d)*PE2 + cgpaGradetomark(e)*OE2 + cgpaGradetomark(f)*PE3 + cgpaGradetomark(g)*PSD + cgpaGradetomark(h)*CIP;
        float cgpa=(float)totalMarks/totalCredits;  
        cumulativeCredits += totalCredits;
        cumulativeGradePoints += totalMarks;
        auto overallCGPA = (float)cumulativeGradePoints / cumulativeCredits;
        cout << "Semester GPA : " << cgpa << endl;
        cout << "Overall CGPA : " << overallCGPA << endl;
        cout<<"No. of backlogs : ";
        int backlog = 0;
        vector<string> grades = {a,b,c,d,e,f,g,h};
        for (const auto &grade : grades) if(cgpaGradetomark(grade)==0) ++backlog;
        cout<<backlog<<endl;

        cout<<"COURSE FOR HONOURS DEGREE \nENTER YOUR  TYPE(1/2) : ";int type;
        cin>>type;
        if(type==1){
            string honoursGrade;
            cout<<"Enter your grade for honours course(CS23D02-CAPSTONE-PROJECT PHASE 1) : ";
        cin>>honoursGrade;
        int  honoursCredits=6;  
        int honoursMarks=cgpaGradetomark(honoursGrade)*honoursCredits;
        float honoursCGPA=(float)honoursMarks/honoursCredits;       
        cout<<"Your Honours CGPA is : "<<honoursCGPA<<endl;
        }
            else if(type==2){
                string he1,he2;
                cout<<"Enter your grade for honours elective-3 : ";cin>>he1;
                cout<<"Enter your grade for honours elective-4 : ";cin>>he2;    
                int honoursCredits=3+3;
                int honoursMarks=cgpaGradetomark(he1)*3 + cgpaGradetomark(he2)*3;
                float honoursCGPA=(float)honoursMarks/honoursCredits;   
                cout<<"Your Honours CGPA is : "<<honoursCGPA<<endl;
            }
             else{
                cout<<"Invalid input for honours degree type!"<<endl;
            }
    }
    void fourthYearFirstSemester(){
        cout<<"Fourth Year First Semester CGPA Calculator !! "<<endl;
        int ETC1=4, PE4=3, PE5=3, PE6=3, ETC2=3, IOC=1;
        cout<<"EMERGING TECHNOLOGY COURSE -1 \nENTER YOUR GRADE : ";
        cin>>a;
        cout<<"PROFESSIONAL ELECTIVE-4 \nENTER YOUR GRADE : ";  
        cin>>b;
        cout<<"PROFESSIONAL ELECTIVE-5 \nENTER YOUR GRADE : ";  
        cin>>c;
        cout<<"PROFESSIONAL ELECTIVE-6 \nENTER YOUR GRADE : ";
        cin>>d;
        cout<<"EMERGING TECHNOLOGY COURSE -2 \nENTER YOUR GRADE : ";
        cin>>e;
        cout<<"INDUSTRY ORIENTED COURSE-3 \nENTER YOUR GRADE : ";
        cin>>f;
        int totalCredits=ETC1+PE4+PE5+PE6+ETC2+IOC;
        int totalMarks=cgpaGradetomark(a)*ETC1 + cgpaGradetomark(b)*PE4 + cgpaGradetomark(c)*PE5 + cgpaGradetomark(d)*PE6 + cgpaGradetomark(e)*ETC2 + cgpaGradetomark(f)*IOC;
        float cgpa=(float)totalMarks/totalCredits;      
        cumulativeCredits += totalCredits;
        cumulativeGradePoints += totalMarks;
        {
            auto overallCGPA = (float)cumulativeGradePoints / cumulativeCredits;
            cout << "Semester GPA : " << cgpa << endl;
            cout << "Overall CGPA : " << overallCGPA << endl;
        }
        cout<<"No. of backlogs : ";int backlog=0;
        if(!cgpaGradetomark(a)){
            backlog++;
        }           if(!cgpaGradetomark(b)){
            backlog++;
        }        if(!cgpaGradetomark(c)){
            backlog++;
        }        if(!cgpaGradetomark(d)){
            backlog++;
        }        if(!cgpaGradetomark(e)){
            backlog++;
        }        if(!cgpaGradetomark(f)){
            backlog++;
        }
        cout<<"COURSE FOR HONOURS DEGREE \nENTER YOUR  TYPE(1/2) : ";int type;
        cin>>type;
        if(type==1){
             cout<<"Enter your grade for honours course(CS23D02-CAPSTONE-PROJECT PHASE 2) : ";
            string honoursGrade;
        cin>>honoursGrade;
        int  honoursCredits=6;  
        int honoursMarks=cgpaGradetomark(honoursGrade)*honoursCredits;
        float honoursCGPA=(float)honoursMarks/honoursCredits;       
        cout<<"Your Honours CGPA is : "<<honoursCGPA<<endl;
        }
            else if(type==2){
                string he1,he2;
                cout<<"Enter your grade for honours elective-5 : ";cin>>he1;
                cout<<"Enter your grade for honours elective-6 : ";cin>>he2;    
                int honoursCredits=3+3;
                int honoursMarks=cgpaGradetomark(he1)*3 + cgpaGradetomark(he2)*3;
                float honoursCGPA=(float)honoursMarks/honoursCredits;   
                cout<<"Your Honours CGPA is : "<<honoursCGPA<<endl;
            }
             else{
                cout<<"Invalid input for honours degree type!"<<endl;
            }}
    void fourthyearsecondSemester(){
        cout<<"Fourth Year Second Semester CGPA Calculator !! "<<endl;
        int PW=8;
        cout<<"PROJECT WORK \nENTER YOUR GRADE : ";
        cin>>a;
        int totalCredits=PW;
        int totalMarks=cgpaGradetomark(a)*PW;
        float cgpa=(float)totalMarks/totalCredits;
        cumulativeCredits += totalCredits;
        cumulativeGradePoints += totalMarks;
        {
            auto overallCGPA = (float)cumulativeGradePoints / cumulativeCredits;
            cout << "Semester GPA : " << cgpa << endl;
            cout << "Overall CGPA : " << overallCGPA << endl;
        }
        cout<<"No. of backlogs : ";
        int backlog = 0;
        vector<string> grades = {a};
        for (const auto &grade : grades) if(!cgpaGradetomark(grade)) ++backlog;
        cout<<backlog<<endl;
    }    

};

double CGPA::cumulativeGradePoints = 0.0;
int CGPA::cumulativeCredits = 0;

int main(){
    int y,s;
    cout<<"CGPA Calculator  for MIT CT DEPARTMENT STUDENTS!! "<<endl;
    cout<<"S : 10\nA+ : 9\nA : 8\nB+ : 7\nB : 6\nC : 5\nRA/U : 0"<<endl;
    while(true){
        cout<<"Enter your year : ";
        cin>>y;
        cout<<"Enter your semester : ";
        cin>>s;
        CGPA obj(y,s);
        cout<<"Calculate another semester? (yes-1/no-0): ";
        int choice;
        cin>>choice;        
        if(choice==0){
            cout<<"Exiting the program. Goodbye!"<<endl;
            break;}
        }
    return 0;}
