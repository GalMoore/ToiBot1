;; Auto-generated. Do not edit!


(when (boundp 'toi_bot_vision::visionMsgOutput)
  (if (not (find-package "TOI_BOT_VISION"))
    (make-package "TOI_BOT_VISION"))
  (shadow 'visionMsgOutput (find-package "TOI_BOT_VISION")))
(unless (find-package "TOI_BOT_VISION::VISIONMSGOUTPUT")
  (make-package "TOI_BOT_VISION::VISIONMSGOUTPUT"))

(in-package "ROS")
;;//! \htmlinclude visionMsgOutput.msg.html


(defclass toi_bot_vision::visionMsgOutput
  :super ros::object
  :slots (_name _detectFace _deltaX _deltaY _canRecognize _emotion _faceArea ))

(defmethod toi_bot_vision::visionMsgOutput
  (:init
   (&key
    ((:name __name) "")
    ((:detectFace __detectFace) nil)
    ((:deltaX __deltaX) 0)
    ((:deltaY __deltaY) 0)
    ((:canRecognize __canRecognize) nil)
    ((:emotion __emotion) "")
    ((:faceArea __faceArea) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _detectFace __detectFace)
   (setq _deltaX (round __deltaX))
   (setq _deltaY (round __deltaY))
   (setq _canRecognize __canRecognize)
   (setq _emotion (string __emotion))
   (setq _faceArea (round __faceArea))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:detectFace
   (&optional __detectFace)
   (if __detectFace (setq _detectFace __detectFace)) _detectFace)
  (:deltaX
   (&optional __deltaX)
   (if __deltaX (setq _deltaX __deltaX)) _deltaX)
  (:deltaY
   (&optional __deltaY)
   (if __deltaY (setq _deltaY __deltaY)) _deltaY)
  (:canRecognize
   (&optional __canRecognize)
   (if __canRecognize (setq _canRecognize __canRecognize)) _canRecognize)
  (:emotion
   (&optional __emotion)
   (if __emotion (setq _emotion __emotion)) _emotion)
  (:faceArea
   (&optional __faceArea)
   (if __faceArea (setq _faceArea __faceArea)) _faceArea)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; bool _detectFace
    1
    ;; int32 _deltaX
    4
    ;; int32 _deltaY
    4
    ;; bool _canRecognize
    1
    ;; string _emotion
    4 (length _emotion)
    ;; int32 _faceArea
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; bool _detectFace
       (if _detectFace (write-byte -1 s) (write-byte 0 s))
     ;; int32 _deltaX
       (write-long _deltaX s)
     ;; int32 _deltaY
       (write-long _deltaY s)
     ;; bool _canRecognize
       (if _canRecognize (write-byte -1 s) (write-byte 0 s))
     ;; string _emotion
       (write-long (length _emotion) s) (princ _emotion s)
     ;; int32 _faceArea
       (write-long _faceArea s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _detectFace
     (setq _detectFace (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32 _deltaX
     (setq _deltaX (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _deltaY
     (setq _deltaY (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _canRecognize
     (setq _canRecognize (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _emotion
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _emotion (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int32 _faceArea
     (setq _faceArea (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get toi_bot_vision::visionMsgOutput :md5sum-) "ffb96e74b49c6230c375e2b578de77a4")
(setf (get toi_bot_vision::visionMsgOutput :datatype-) "toi_bot_vision/visionMsgOutput")
(setf (get toi_bot_vision::visionMsgOutput :definition-)
      "
string name
bool detectFace
int32 deltaX
int32 deltaY
bool canRecognize
string emotion
int32 faceArea

")



(provide :toi_bot_vision/visionMsgOutput "ffb96e74b49c6230c375e2b578de77a4")


