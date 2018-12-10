; Auto-generated. Do not edit!


(cl:in-package coordination_publisher-msg)


;//! \htmlinclude coordination.msg.html

(cl:defclass <coordination> (roslisp-msg-protocol:ros-message)
  ((aX
    :reader aX
    :initarg :aX
    :type cl:float
    :initform 0.0)
   (aY
    :reader aY
    :initarg :aY
    :type cl:float
    :initform 0.0)
   (aZ
    :reader aZ
    :initarg :aZ
    :type cl:float
    :initform 0.0))
)

(cl:defclass coordination (<coordination>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <coordination>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'coordination)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name coordination_publisher-msg:<coordination> is deprecated: use coordination_publisher-msg:coordination instead.")))

(cl:ensure-generic-function 'aX-val :lambda-list '(m))
(cl:defmethod aX-val ((m <coordination>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader coordination_publisher-msg:aX-val is deprecated.  Use coordination_publisher-msg:aX instead.")
  (aX m))

(cl:ensure-generic-function 'aY-val :lambda-list '(m))
(cl:defmethod aY-val ((m <coordination>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader coordination_publisher-msg:aY-val is deprecated.  Use coordination_publisher-msg:aY instead.")
  (aY m))

(cl:ensure-generic-function 'aZ-val :lambda-list '(m))
(cl:defmethod aZ-val ((m <coordination>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader coordination_publisher-msg:aZ-val is deprecated.  Use coordination_publisher-msg:aZ instead.")
  (aZ m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <coordination>) ostream)
  "Serializes a message object of type '<coordination>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'aX))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'aY))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'aZ))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <coordination>) istream)
  "Deserializes a message object of type '<coordination>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'aX) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'aY) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'aZ) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<coordination>)))
  "Returns string type for a message object of type '<coordination>"
  "coordination_publisher/coordination")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'coordination)))
  "Returns string type for a message object of type 'coordination"
  "coordination_publisher/coordination")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<coordination>)))
  "Returns md5sum for a message object of type '<coordination>"
  "e9ad96bdd5cf5d5e53c59d1a240ad03f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'coordination)))
  "Returns md5sum for a message object of type 'coordination"
  "e9ad96bdd5cf5d5e53c59d1a240ad03f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<coordination>)))
  "Returns full string definition for message of type '<coordination>"
  (cl:format cl:nil "float32 aX~%float32 aY~%float32 aZ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'coordination)))
  "Returns full string definition for message of type 'coordination"
  (cl:format cl:nil "float32 aX~%float32 aY~%float32 aZ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <coordination>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <coordination>))
  "Converts a ROS message object to a list"
  (cl:list 'coordination
    (cl:cons ':aX (aX msg))
    (cl:cons ':aY (aY msg))
    (cl:cons ':aZ (aZ msg))
))
