;; Auto-generated. Do not edit!


(when (boundp 'toi_bot_speakers::speakersCommand)
  (if (not (find-package "TOI_BOT_SPEAKERS"))
    (make-package "TOI_BOT_SPEAKERS"))
  (shadow 'speakersCommand (find-package "TOI_BOT_SPEAKERS")))
(unless (find-package "TOI_BOT_SPEAKERS::SPEAKERSCOMMAND")
  (make-package "TOI_BOT_SPEAKERS::SPEAKERSCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude speakersCommand.msg.html


(defclass toi_bot_speakers::speakersCommand
  :super ros::object
  :slots (_response ))

(defmethod toi_bot_speakers::speakersCommand
  (:init
   (&key
    ((:response __response) "")
    )
   (send-super :init)
   (setq _response (string __response))
   self)
  (:response
   (&optional __response)
   (if __response (setq _response __response)) _response)
  (:serialization-length
   ()
   (+
    ;; string _response
    4 (length _response)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _response
       (write-long (length _response) s) (princ _response s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _response
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _response (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get toi_bot_speakers::speakersCommand :md5sum-) "6de314e2dc76fbff2b6244a6ad70b68d")
(setf (get toi_bot_speakers::speakersCommand :datatype-) "toi_bot_speakers/speakersCommand")
(setf (get toi_bot_speakers::speakersCommand :definition-)
      "string response

")



(provide :toi_bot_speakers/speakersCommand "6de314e2dc76fbff2b6244a6ad70b68d")


