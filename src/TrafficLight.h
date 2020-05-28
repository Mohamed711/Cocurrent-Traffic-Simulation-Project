#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <mutex>
#include <deque>
#include <condition_variable>
#include "TrafficObject.h"

// forward declarations to avoid include cycle
class Vehicle;

/* Declaration of class "MessageQueue" */
template <class T>
class MessageQueue
{
public:
    T receive();
    void send(T &&msg);

private:
    std::mutex _mutex;
    std::condition_variable _condition;
    std::deque<T> _queue;
};

// Phases of the traffic light
enum TrafficLightPhase
{
    red,
    green,
};

/* Declaration of class "TrafficLight" */
class TrafficLight : public TrafficObject
{
public:
    // constructor / desctructor
    TrafficLight();

    // getters / setters
    TrafficLightPhase getCurrentPhase();

    // typical behaviour methods
    void waitForGreen();
    void simulate();

private:
    // typical behaviour methods
    void cycleThroughPhases();
    MessageQueue<TrafficLightPhase> trafficLight;
    TrafficLightPhase _currentPhase;
};

#endif