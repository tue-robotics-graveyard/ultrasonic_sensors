#!/usr/bin/python
# -*- coding: utf-8 -*-

# Start up ROS pieces.
PKG = 'ultrasonic_sensors'
import roslib; roslib.load_manifest(PKG)
import rospy
import tf

# ROS messages.
from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import Range

class ReadSensors():
	def __init__(self):
		
		rate = float(rospy.get_param('~rate', '1.0'))
		
		max_range = 0.3
		self.got_new_msg = False
		self.range_msg1 = Range()
		self.range_msg2 = Range()
		self.range_msg3 = Range()
		self.range_msg4 = Range()
		self.range_msg1.min_range = 0.02
		self.range_msg1.max_range = max_range
		self.range_msg1.radiation_type = self.range_msg1.ULTRASOUND
		self.range_msg1.field_of_view = 0.7; # 40 degrees
		self.range_msg1.header.frame_id = "/sergio/base_sonar1";
		self.range_msg2.min_range = 0.02
		self.range_msg2.max_range = max_range
		self.range_msg2.radiation_type = self.range_msg1.ULTRASOUND
		self.range_msg2.field_of_view = 0.7; # 40 degrees
		self.range_msg2.header.frame_id = "/sergio/base_sonar2";
		self.range_msg3.min_range = 0.02
		self.range_msg3.max_range = max_range
		self.range_msg3.radiation_type = self.range_msg1.ULTRASOUND
		self.range_msg3.field_of_view = 0.7; # 40 degrees
		self.range_msg3.header.frame_id = "/sergio/base_sonar3";
		self.range_msg4.min_range = 0.02
		self.range_msg4.max_range = max_range
		self.range_msg4.radiation_type = self.range_msg1.ULTRASOUND
		self.range_msg4.field_of_view = 0.7; # 40 degrees
		self.range_msg4.header.frame_id = "/sergio/base_sonar4";
		
		# Create subscribers and publishers.
		sub_ultrasone = rospy.Subscriber("ultrasonic", Float32MultiArray, self.ultrasone_callback)
		pub_sonar1 = rospy.Publisher("sonar1", Range)
		pub_sonar2 = rospy.Publisher("sonar2", Range)
		pub_sonar3 = rospy.Publisher("sonar3", Range)
		pub_sonar4 = rospy.Publisher("sonar4", Range)

		# Main while loop.
		while not rospy.is_shutdown():
			# Publish new data if we got a new message.
			if self.got_new_msg:
				self.range_msg1.header.stamp = rospy.get_rostime()
				pub_sonar1.publish(self.range_msg1)
				self.range_msg2.header.stamp = rospy.get_rostime()
				pub_sonar2.publish(self.range_msg2)
				self.range_msg3.header.stamp = rospy.get_rostime()
				pub_sonar3.publish(self.range_msg3)
				self.range_msg4.header.stamp = rospy.get_rostime()
				pub_sonar4.publish(self.range_msg4)
				self.got_new_msg = False
			else:
				self.range_msg1.header.stamp = rospy.get_rostime()
				pub_sonar1.publish(self.range_msg1)
				self.range_msg2.header.stamp = rospy.get_rostime()
				pub_sonar2.publish(self.range_msg2)
				self.range_msg3.header.stamp = rospy.get_rostime()
				pub_sonar3.publish(self.range_msg3)
				self.range_msg4.header.stamp = rospy.get_rostime()
				pub_sonar4.publish(self.range_msg4)
			
			# Sleep for a while before publishing new messages. Division is so rate != period.
			if rate:
				rospy.sleep(1/rate)
			else:
				rospy.sleep(1.0)

	# Ultrasone callback function.
	def ultrasone_callback(self, msg):
		# Get ranges.
		self.range_msg1.range = min(msg.data[0], self.range_msg1.max_range)
		self.range_msg2.range = min(msg.data[1], self.range_msg2.max_range)
		self.range_msg3.range = min(msg.data[2], self.range_msg3.max_range)
		self.range_msg4.range = min(msg.data[3], self.range_msg4.max_range)
		self.got_new_msg = True

# Main function.
if __name__ == '__main__':
	# Initialize the node and name it.
	rospy.init_node('read_sensors')
	# Go to class functions that do all the heavy lifting. Do error checking.
	try:
		read_sensors = ReadSensors()
	except rospy.ROSInterruptException: pass
