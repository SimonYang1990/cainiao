#ifndef O2O_ORDER_H
#define O2O_ORDER_H

#include"location.h"

using namespace std;
class o2o_order
{
    public:
        o2o_order();
        virtual ~o2o_order();


        o2o_order(string s,int p,int d,int pt,int dt,int n,int site);
        // The information of the o2o order
        void setID(string str);
        string id();

        void setPickupLoc(int index);
        int pickupLoc();

        void setDeliveryLoc(int index);
        int deliveryLoc();

        void setPickupTime(int time);
        int pickupTime();

        void setDeliveryTime(int time);
        int deliveryTime();

        void setUnload(int n);
        int unload();

        void setSiteLoc(int index);
        int siteLoc();

        void setWillLate();
        bool willLate();

        void setWillOutTime();
        bool willOutTime();

        void setLatestTime(int time);
        int latestTime();

        void setMustLateTime(int time);
        void addMustLateTime(int time);
        int mustLateTime();


    protected:

    private:
        string id_;                         // �������
        int pickupLoc_,deliveryLoc_;        // ȡ����ַ��ţ��ͻ���ַ���
        int pickupTime_,deliveryTime_;      // ȡ��ʱ�䣬����ͻ�ʱ��
        int unload_;                        // ��������
        int siteLoc_;                       // ���ڵ������ַ���
        bool willLate_;                     // �����Ƿ�һ����ٵ�
        bool willOutTime_;                  // �����Ƿ�һ������������8��
        int latestTime_;                    // ���һ���ٵ���������Ե������͵��ʱ��
        int mustLateTime_;                  // ���һ���ٵ����ٵ����ۼ�ʱ��
};

#endif // O2O_ORDER_H
