;; Auto-generated. Do not edit!


(when (boundp 'motors::motorsCommand)
  (if (not (find-package "MOTORS"))
    (make-package "MOTORS"))
  (shadow 'motorsCommand (find-package "MOTORS")))
(unless (find-package "MOTORS::MOTORSCOMMAND")
  (make-package "MOTORS::MOTORSCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude motorsCommand.msg.html


(defclass motors::motorsCommand
  :super ros::object
  :slots (_deltaX _deltaY _faceArea _setnence ))

(defmethod motors::motorsCommand
  (:init
   (&key
    ((:deltaX __deltaX) 0)
    ((:deltaY __deltaY) 0)
    ((:faceArea __faceArea) 0)
    ((:setnence __setnence) "")
    )
   (send-super :init)
   (setq _deltaX (round __deltaX))
   (setq _deltaY (round __deltaY))
   (setq _faceArea (round __faceArea))
   (setq _setnence (string __setnence))
   self)
  (:deltaX
   (&optional __deltaX)
   (if __deltaX (setq _deltaX __deltaX)) _deltaX)
  (:deltaY
   (&optional __deltaY)
   (if __deltaY (setq _deltaY __deltaY)) _deltaY)
  (:faceArea
   (&optional __faceArea)
   (if __faceArea (setq _faceArea __faceArea)) _faceArea)
  (:setnence
   (&optional __setnence)
   (if __setnence (setq _setnence __setnence)) _setnence)
  (:serialization-length
   ()
   (+
    ;; int32 _deltaX
    4
    ;; int32 _deltaY
    4
    ;; int32 _faceArea
    4
    ;; string _setnence
    4 (length _setnence)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _deltaX
       (write-long _deltaX s)
     ;; int32 _deltaY
       (write-long _deltaY s)
     ;; int32 _faceArea
       (write-long _faceArea s)
     ;; string _setnence
       (write-long (length _setnence) s) (princ _setnence s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _deltaX
     (setq _deltaX (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _deltaY
     (setq _deltaY (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _faceArea
     (setq _faceArea (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _setnence
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _setnence (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get motors::motorsCommand :md5sum-) "c9eec707e4d0b5f449400290d53d427d")
(setf (get motors::motorsCommand :datatype-) "motors/motorsCommand")
(setf (get motors::motorsCommand :definition-)
      "int32 deltaX
int32 deltaY
int32 faceArea
string setnence


")



(provide :motors/motorsCommand "c9eec707e4d0b5f449400290d53d427d")


