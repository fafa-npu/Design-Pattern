#include <iostream>
#include "state_work.h"

using namespace std;

void Work::SetHour(double pHour) {
    this->_hour = pHour;
}

double Work::GetHour() {
    return this->_hour;
}

void Work::SetWorkFinished(bool finished) {
    this->_workFinished = finished;
}

bool Work::IsWorkFinished() {
    return this->_workFinished;
}

void Work::SetState(State * pState) {
    this->_curState = pState;
}

void Work::WriteProgram() {
    this->_curState->WriteProgram(this);
}


void ForenoonState::WriteProgram(Work * work) {
    if (work->GetHour() < 12) {
        cout << "current time is " << work->GetHour() << ". "
            << "Forenoon." << endl;
    } else {
        work->SetState(new NoonState());
        work->WriteProgram();
    }
}


void NoonState::WriteProgram(Work * work) {
    if (work->GetHour() < 13) {
        cout << "current time is " << work->GetHour() << ". "
            << "Noon." << endl;
    } else {
        work->SetState(new AfternoonState());
        work->WriteProgram();
    }
}
void AfternoonState::WriteProgram(Work * work) {
    if (work->GetHour() < 17) {
        cout << "current time is " << work->GetHour() << ". "
            << "Afternoon." << endl;
    } else {
        work->SetState(new EveningState());
        work->WriteProgram();
    }
}
void EveningState::WriteProgram(Work * work) {
    if (work->IsWorkFinished()) {
        work->SetState(new RestState());
        work->WriteProgram();
        return;
    }
    if (work->GetHour() < 21) {
        cout << "current time is " << work->GetHour() << ". "
            << "Evening." << endl;
    } else {
        work->SetState(new SleepState());
        work->WriteProgram();
    }
}

void RestState::WriteProgram(Work * work) {
    cout << "current time is " << work->GetHour() << ". "
        << "Rest." << endl;
}

void SleepState::WriteProgram(Work * work) {
    cout << "current time is " << work->GetHour() << ". "
        << "Sleeping." << endl;
}


int main() {
    Work * work = new Work();
    work->SetHour(10);
    work->SetState(new ForenoonState());
    work->WriteProgram();

    work->SetHour(12.3);
    work->WriteProgram();

    work->SetHour(14);
    work->WriteProgram();
    work->SetHour(15);
    work->WriteProgram();

    work->SetWorkFinished(false);
    work->SetHour(18);
    work->WriteProgram();

    work->SetWorkFinished(true);
    work->SetHour(19);
    work->WriteProgram();

    return 0;
}
