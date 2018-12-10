
(cl:in-package :asdf)

(defsystem "coordination_publisher-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "coordination" :depends-on ("_package_coordination"))
    (:file "_package_coordination" :depends-on ("_package"))
  ))