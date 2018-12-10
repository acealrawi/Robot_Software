
(cl:in-package :asdf)

(defsystem "ar_publisher-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ARMarker" :depends-on ("_package_ARMarker"))
    (:file "_package_ARMarker" :depends-on ("_package"))
  ))