
(cl:in-package :asdf)

(defsystem "moving_core-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "PoseMessage" :depends-on ("_package_PoseMessage"))
    (:file "_package_PoseMessage" :depends-on ("_package"))
  ))