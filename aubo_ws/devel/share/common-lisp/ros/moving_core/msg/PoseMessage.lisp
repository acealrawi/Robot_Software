; Auto-generated. Do not edit!


(cl:in-package moving_core-msg)


;//! \htmlinclude PoseMessage.msg.html

(cl:defclass <PoseMessage> (roslisp-msg-protocol:ros-message)
  ((pose
    :reader pose
    :initarg :pose
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose)))
)

(cl:defclass PoseMessage (<PoseMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PoseMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PoseMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name moving_core-msg:<PoseMessage> is deprecated: use moving_core-msg:PoseMessage instead.")))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <PoseMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader moving_core-msg:pose-val is deprecated.  Use moving_core-msg:pose instead.")
  (pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PoseMessage>) ostream)
  "Serializes a message object of type '<PoseMessage>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PoseMessage>) istream)
  "Deserializes a message object of type '<PoseMessage>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PoseMessage>)))
  "Returns string type for a message object of type '<PoseMessage>"
  "moving_core/PoseMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PoseMessage)))
  "Returns string type for a message object of type 'PoseMessage"
  "moving_core/PoseMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PoseMessage>)))
  "Returns md5sum for a message object of type '<PoseMessage>"
  "f192399f711a48924df9a394d37edd67")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PoseMessage)))
  "Returns md5sum for a message object of type 'PoseMessage"
  "f192399f711a48924df9a394d37edd67")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PoseMessage>)))
  "Returns full string definition for message of type '<PoseMessage>"
  (cl:format cl:nil "geometry_msgs/Pose pose~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PoseMessage)))
  "Returns full string definition for message of type 'PoseMessage"
  (cl:format cl:nil "geometry_msgs/Pose pose~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PoseMessage>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PoseMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'PoseMessage
    (cl:cons ':pose (pose msg))
))
