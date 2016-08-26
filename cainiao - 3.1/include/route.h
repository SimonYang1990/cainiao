#ifndef ROUTE_H
#define ROUTE_H

#include<iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include<cstring>
#include<string>
#include<utility> //std::pair,std::get
#include<bitset>
#include<assert.h>
#include"record.h"
#include"visitnode.h"

using namespace std;
class route
{
    public:
        route();
        virtual ~route();


        void printRouteInformation(){
            for(std::size_t i = 0;i<records.size();++i){
                records[i].printRecord();
            }
            cout<<"The start time is "<<startTime<<"The end time is "<<endTime<<endl;
            cout<<"The punishTime is "<<punishTime<<" The total cost time is "<<totalCostTime<<endl;
        }
        /*Courier ID method*/
        int getCourierID(){
            return courierID;
        }
        void setCourierID(int id){
            courierID = id;
        }
        /*Start time methods*/
        int getStartTime(){
            return startTime;
        }
        void setStartTime(int time){
            startTime = time;
        }
        void addStartTime(int time){
            startTime +=time;
        }
        /*End time methods*/
        int getEndTime(){
            return endTime;
        }
        void setEndTime(int time){
            endTime = time;
        }
        void addEndTime(int time){
            endTime += time;
        }
        /*Total cost time methods*/
        int getTotalCostTime(){
            return totalCostTime;
        }
        void setTotalCostTime(int time){
            totalCostTime = time;
        }
        void addTotalCostTime(int time){
            totalCostTime += time;
        }
        /*Punish time methods*/
        int getPunishTime(){
            return punishTime;
        }
        void setPunishTime(int time){
            punishTime = time;
        }
        void addPunishTime(int time){
            punishTime += time;
        }
        /*Current load methods*/
        int getCurrentLoad(){
            return currentLoad;
        }
        void setCurrentLoad(int load){
            currentLoad = load;
        }
        void addCurrentLoad(int load){
            currentLoad += load;
        }
        /* Visit spot node method*/
        void addVisitNode(visitnode v){
            vNodes.push_back(v);
        }
        std::size_t vNodesSize(){
            return vNodes.size();
        }
        void insertVisitNode(int pos,visitnode v){
            vNodes.insert(vNodes.begin()+pos,v);
        }
        void eraseVisitNode(int pos){
            vNodes.erase(vNodes.begin()+pos);
        }
        bool vNodesEmpty(){
            return vNodes.empty();
        }
        /* Records method*/
         void addRecord(record re){
            records.push_back(re);
        }

        visitnode &operator[](const size_t i){
            return vNodes[i];
        }

        void calTotalCost(){
            totalCostTime = endTime - startTime + punishTime;
        }

        void toCSV(ofstream &myfile){
            for(std::vector<record>::iterator it = records.begin();it!=records.end();++it){
                myfile<<it->toString();
            }
        }

        int getEndLocIndex(){
            assert(!vNodes.empty());
            return vNodes[vNodes.size()-1].locIndex();
        }
        void setStartLocIndex(int index){
            startLocIndex = index;
        }
        int getStartLocIndex(){
            return startLocIndex;
        }

    protected:


    private:
        int courierID;          // ���Ա���
        int startTime;          // ·����ʼʱ��
        int endTime;            // ·������ʱ��
        int totalCostTime;      // �ܵ�����ʱ�䣬�����ͷ�ʱ��
        int punishTime;         // �ͷ�ʱ��
        int currentLoad;        // Я����������
        int startLocIndex;      // ��ʼ�������ַ���

        vector<visitnode> vNodes; // ·�����η��ʵĽڵ�
        vector<record> records;   // ·���ļ�¼

};

#endif // ROUTE_H
