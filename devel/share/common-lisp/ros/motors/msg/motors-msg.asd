
(cl:in-package :asdf)

(defsystem "motors-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "motorsCommand" :depends-on ("_package_motorsCommand"))
    (:file "_package_motorsCommand" :depends-on ("_package"))
  ))