;; Auto-generated. Do not edit!


(when (boundp 'moving_core::PoseMessage)
  (if (not (find-package "MOVING_CORE"))
    (make-package "MOVING_CORE"))
  (shadow 'PoseMessage (find-package "MOVING_CORE")))
(unless (find-package "MOVING_CORE::POSEMESSAGE")
  (make-package "MOVING_CORE::POSEMESSAGE"))

(in-package "ROS")
;;//! \htmlinclude PoseMessage.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass moving_core::PoseMessage
  :super ros::object
  :slots (_pose ))

(defmethod moving_core::PoseMessage
  (:init
   (&key
    ((:pose __pose) (instance geometry_msgs::Pose :init))
    )
   (send-super :init)
   (setq _pose __pose)
   self)
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose _pose
    (send _pose :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose _pose
       (send _pose :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;;
   self)
  )

(setf (get moving_core::PoseMessage :md5sum-) "f192399f711a48924df9a394d37edd67")
(setf (get moving_core::PoseMessage :datatype-) "moving_core/PoseMessage")
(setf (get moving_core::PoseMessage :definition-)
      "geometry_msgs/Pose pose
================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :moving_core/PoseMessage "f192399f711a48924df9a394d37edd67")


