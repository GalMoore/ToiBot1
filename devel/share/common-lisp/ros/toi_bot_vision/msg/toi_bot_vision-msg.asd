
(cl:in-package :asdf)

(defsystem "toi_bot_vision-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "visionMsgCommand" :depends-on ("_package_visionMsgCommand"))
    (:file "_package_visionMsgCommand" :depends-on ("_package"))
    (:file "visionMsgOutput" :depends-on ("_package_visionMsgOutput"))
    (:file "_package_visionMsgOutput" :depends-on ("_package"))
  ))