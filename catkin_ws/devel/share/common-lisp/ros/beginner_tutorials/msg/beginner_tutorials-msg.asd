
(cl:in-package :asdf)

(defsystem "beginner_tutorials-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "IntwithHeader" :depends-on ("_package_IntwithHeader"))
    (:file "_package_IntwithHeader" :depends-on ("_package"))
  ))