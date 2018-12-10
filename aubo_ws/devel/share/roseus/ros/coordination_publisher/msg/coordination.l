;; Auto-generated. Do not edit!


(when (boundp 'coordination_publisher::coordination)
  (if (not (find-package "COORDINATION_PUBLISHER"))
    (make-package "COORDINATION_PUBLISHER"))
  (shadow 'coordination (find-package "COORDINATION_PUBLISHER")))
(unless (find-package "COORDINATION_PUBLISHER::COORDINATION")
  (make-package "COORDINATION_PUBLISHER::COORDINATION"))

(in-package "ROS")
;;//! \htmlinclude coordination.msg.html


(defclass coordination_publisher::coordination
  :super ros::object
  :slots (_aX _aY _aZ ))

(defmethod coordination_publisher::coordination
  (:init
   (&key
    ((:aX __aX) 0.0)
    ((:aY __aY) 0.0)
    ((:aZ __aZ) 0.0)
    )
   (send-super :init)
   (setq _aX (float __aX))
   (setq _aY (float __aY))
   (setq _aZ (float __aZ))
   self)
  (:aX
   (&optional __aX)
   (if __aX (setq _aX __aX)) _aX)
  (:aY
   (&optional __aY)
   (if __aY (setq _aY __aY)) _aY)
  (:aZ
   (&optional __aZ)
   (if __aZ (setq _aZ __aZ)) _aZ)
  (:serialization-length
   ()
   (+
    ;; float32 _aX
    4
    ;; float32 _aY
    4
    ;; float32 _aZ
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _aX
       (sys::poke _aX (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _aY
       (sys::poke _aY (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _aZ
       (sys::poke _aZ (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _aX
     (setq _aX (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _aY
     (setq _aY (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _aZ
     (setq _aZ (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get coordination_publisher::coordination :md5sum-) "e9ad96bdd5cf5d5e53c59d1a240ad03f")
(setf (get coordination_publisher::coordination :datatype-) "coordination_publisher/coordination")
(setf (get coordination_publisher::coordination :definition-)
      "float32 aX
float32 aY
float32 aZ

")



(provide :coordination_publisher/coordination "e9ad96bdd5cf5d5e53c59d1a240ad03f")


