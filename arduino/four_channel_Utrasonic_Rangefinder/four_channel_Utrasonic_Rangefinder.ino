/* 
 
  ================================================================================================
   4-channel ultrasonic rangefinder
   
   This sketch reads  PING ultrasonic rangefinders and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse
   to return.  The length of the returning pulse is proportional to
   the distance of the object from the sensor.
   
   Ruud, Nov 2014
 ==================================================================================================    
   Added a ROS communication layer
   
   Ton, Nov 2014
 ========================================================================

 */

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Float32MultiArray.h>
#include <sensor_msgs/Range.h>

ros::NodeHandle  nh;

std_msgs::Float32MultiArray float_array_msg;
ros::Publisher ultrasonic( "ultrasonic", &float_array_msg);
sensor_msgs::Range range_msg;
ros::Publisher pub_range( "range_data", &range_msg);

char frameid[] = "/us_ranger";

// pin number of the sensor's output:
const int pingPin = 11;
const int pingPin1 = 7;
const int pingPin2 = 12;
const int pingPin3 = 10;


void setup() {
  nh.initNode();
  
  
  float_array_msg.data_length=4;
  float_array_msg.data = (float *)malloc(sizeof(float)*4);
  for (int i=0; i<4; i++){
    float_array_msg.data[i] = 0.0;
  }
  
  
  nh.advertise(ultrasonic);
  
  // range message
  nh.advertise(pub_range);
  
  range_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range_msg.header.frame_id =  frameid;
  range_msg.field_of_view = 0.01; // to be checked!!!
  range_msg.min_range = 0.2; // 0.2 from datasheet
  range_msg.max_range = 2.9; // 3.0 from datasheet
  
}

void loop()
{ 
  
  float duration, cm, duration1, cm1, duration2, cm2, duration3, cm3;

  //SENSOR_0
  
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
 
  
  //SENSOR_1
  
  pinMode(pingPin1, OUTPUT);
  digitalWrite(pingPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin1, LOW);

    pinMode(pingPin1, INPUT);
  duration1 = pulseIn(pingPin1, HIGH);

  cm1 = microsecondsToCentimeters(duration1);
 
  
  //SENSOR_2
  
  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);

  pinMode(pingPin2, INPUT);
  duration2 = pulseIn(pingPin2, HIGH);

  cm2 = microsecondsToCentimeters(duration2);
  
  //SENSOR_3
  
  pinMode(pingPin3, OUTPUT);
  digitalWrite(pingPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin3, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin3, LOW);

  pinMode(pingPin3, INPUT);
  duration3 = pulseIn(pingPin3, HIGH);

  cm3 = microsecondsToCentimeters(duration3);
  
  float_array_msg.data[0] = cm;
  float_array_msg.data[1] = cm1;
  float_array_msg.data[2] = cm2;
  float_array_msg.data[3] = cm3;
  
 
  //Publish to ros
  ultrasonic.publish(&float_array_msg);
  
  range_msg.range = cm;
  range_msg.header.stamp = nh.now();
  pub_range.publish(&range_msg);
    
  nh.spinOnce();
 
 
  
  delay(100);
}


//  converteer naar centimeters

float microsecondsToCentimeters(float microseconds)
{
  // The speed of sound is 340 m/s or 2900 microseconds per meter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 2900 / 2;
}
