/**
 * author : zhaohua
 * date : June 17th, 2016
 * discription : 《大话设计模式》，（程杰）。状态模式示例。page167
 * **/

#ifndef STATE_WORK_H_
#define STATE_WORK_H_

class Work;
class State;
class ForenoonState;
class NoonState;
class AfternoonState;
class EveningState;
class RestState;
class SleepState;

class Work {
    private :
        State * _curState;
        double _hour;
        bool _workFinished;
    public :
        void SetHour(double pHour);
        double GetHour();
        void SetWorkFinished(bool finished);
        bool IsWorkFinished();
        void SetState(State * pState);
        void WriteProgram();
};

class State {
    public :
        virtual void WriteProgram(Work * work) = 0;
};

class ForenoonState : public State {
    public :
        void WriteProgram(Work * work);
};

class NoonState : public State {
    public :
        void WriteProgram(Work * work);
};

class AfternoonState : public State {
    public :
        void WriteProgram(Work * work);
};

class EveningState : public State {
    public :
        void WriteProgram(Work * work);
};

class RestState : public State {
    public :
        void WriteProgram(Work * work);
};

class SleepState : public State {
    public :
        void WriteProgram(Work * work);
};
#endif
