/**
 * author : zhaohua
 * date : July 12, 2016
 * discription : 《大话设计模式》， （程杰），解释器模式，音乐解释器。page 284
 * **/

#include <iostream>

using namespace std;

/* 演奏内容 */
class PlayContext {
    private :
        // 演奏文本
        string _text;
    public :
        void SetText(string pText) {
            this->_text = pText;
        }

        string GetText() {
            return this->_text;
        }
};

/* 表达式 */
class Expression {
    public :
        void Interpret(PlayContext * context) {
            if (context->GetText().length() == 0) {
                cout << "text size is zero!" << endl;
                return ;
            } else {
                char playKey = context->GetText()[0];
                context->SetText(context->GetText().substr(2, context->GetText().length()));
                string strPlayValue = context->GetText().substr(0, context->GetText().find(' '));
                context->SetText(context->GetText().substr(context->GetText().find(' ') + 1,  context->GetText().length()));
                char * cPlayValue;
                int len = strPlayValue.length();
                cPlayValue = (char *)malloc((len+1) * sizeof(char));
                strPlayValue.copy(cPlayValue, len, 0);
                double playValue = atof(cPlayValue);
                Excute(playKey, playValue);
                //cout << playKey << endl;
                //cout << playValue << endl;
                //cout << context->GetText() << endl;
            }
        }

        virtual void Excute(char key, double value) = 0;
};


/* 音符 */
class Note : public Expression {
    void Excute(char key, double value) {
        string note = "";
        if (key == 'C') note = "1";
        else if (key == 'D') note = "2";
        else if (key == 'E') note = "3";
        else if (key == 'F') note = "4";
        else if (key == 'G') note = "5";
        else if (key == 'A') note = "6";
        else if (key == 'B') note = "7";

        cout << note << " ";
    }
};


/* 音阶 */
class Scale : public Expression {
    void Excute(char key, double value) {
        string scale = "";
        switch ((int)value) {
            case 1:
                scale = "low";
                break;
            case 2:
                scale = "middle";
                break;
            case 3:
                scale = "high";
                break;
        }

        cout << scale << " ";
    }
};

int main() {
    PlayContext * context = new PlayContext();
    context->SetText("O 3.2 E 0.5 G 0.5 A 3");
    Expression * expr = NULL;
    try {
        while (context->GetText().length() > 0) {
            if (context->GetText()[0] == 'O') {
                expr = new Scale();
            } else {
                expr = new Note();
            }
            expr->Interpret(context);
        }
    } catch (exception ex) {
    }

    return 0;
}
