
(cl:in-package :asdf)

(defsystem "toi_bot_stt-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "speechTT" :depends-on ("_package_speechTT"))
    (:file "_package_speechTT" :depends-on ("_package"))
  ))