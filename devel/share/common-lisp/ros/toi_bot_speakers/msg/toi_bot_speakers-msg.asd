
(cl:in-package :asdf)

(defsystem "toi_bot_speakers-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "speakersCommand" :depends-on ("_package_speakersCommand"))
    (:file "_package_speakersCommand" :depends-on ("_package"))
  ))