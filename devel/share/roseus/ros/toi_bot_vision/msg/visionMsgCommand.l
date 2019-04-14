;; Auto-generated. Do not edit!


(when (boundp 'toi_bot_vision::visionMsgCommand)
  (if (not (find-package "TOI_BOT_VISION"))
    (make-package "TOI_BOT_VISION"))
  (shadow 'visionMsgCommand (find-package "TOI_BOT_VISION")))
(unless (find-package "TOI_BOT_VISION::VISIONMSGCOMMAND")
  (make-package "TOI_BOT_VISION::VISIONMSGCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude visionMsgCommand.msg.html


(defclass toi_bot_vision::visionMsgCommand
  :super ros::object
  :slots (_visionStateCommand _personName ))

(defmethod toi_bot_vision::visionMsgCommand
  (:init
   (&key
    ((:visionStateCommand __visionStateCommand) 0)
    ((:personName __personName) "")
    )
   (send-super :init)
   (setq _visionStateCommand (round __visionStateCommand))
   (setq _personName (string __personName))
   self)
  (:visionStateCommand
   (&optional __visionStateCommand)
   (if __visionStateCommand (setq _visionStateCommand __visionStateCommand)) _visionStateCommand)
  (:personName
   (&optional __personName)
   (if __personName (setq _personName __personName)) _personName)
  (:serialization-length
   ()
   (+
    ;; int8 _visionStateCommand
    1
    ;; string _personName
    4 (length _personName)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _visionStateCommand
       (write-byte _visionStateCommand s)
     ;; string _personName
       (write-long (length _personName) s) (princ _personName s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _visionStateCommand
     (setq _visionStateCommand (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _visionStateCommand 127) (setq _visionStateCommand (- _visionStateCommand 256)))
   ;; string _personName
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _personName (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get toi_bot_vision::visionMsgCommand :md5sum-) "69b80dd6addeec87f2c5298e187d1d3a")
(setf (get toi_bot_vision::visionMsgCommand :datatype-) "toi_bot_vision/visionMsgCommand")
(setf (get toi_bot_vision::visionMsgCommand :definition-)
      "int8 visionStateCommand

string personName

")



(provide :toi_bot_vision/visionMsgCommand "69b80dd6addeec87f2c5298e187d1d3a")


