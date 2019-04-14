;; Auto-generated. Do not edit!


(when (boundp 'toi_bot_stt::speechTT)
  (if (not (find-package "TOI_BOT_STT"))
    (make-package "TOI_BOT_STT"))
  (shadow 'speechTT (find-package "TOI_BOT_STT")))
(unless (find-package "TOI_BOT_STT::SPEECHTT")
  (make-package "TOI_BOT_STT::SPEECHTT"))

(in-package "ROS")
;;//! \htmlinclude speechTT.msg.html


(defclass toi_bot_stt::speechTT
  :super ros::object
  :slots (_query _response _intent ))

(defmethod toi_bot_stt::speechTT
  (:init
   (&key
    ((:query __query) "")
    ((:response __response) "")
    ((:intent __intent) "")
    )
   (send-super :init)
   (setq _query (string __query))
   (setq _response (string __response))
   (setq _intent (string __intent))
   self)
  (:query
   (&optional __query)
   (if __query (setq _query __query)) _query)
  (:response
   (&optional __response)
   (if __response (setq _response __response)) _response)
  (:intent
   (&optional __intent)
   (if __intent (setq _intent __intent)) _intent)
  (:serialization-length
   ()
   (+
    ;; string _query
    4 (length _query)
    ;; string _response
    4 (length _response)
    ;; string _intent
    4 (length _intent)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _query
       (write-long (length _query) s) (princ _query s)
     ;; string _response
       (write-long (length _response) s) (princ _response s)
     ;; string _intent
       (write-long (length _intent) s) (princ _intent s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _query
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _query (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _response
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _response (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _intent
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _intent (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get toi_bot_stt::speechTT :md5sum-) "c2e0321a6d60d7971f3d93f2eaf3408e")
(setf (get toi_bot_stt::speechTT :datatype-) "toi_bot_stt/speechTT")
(setf (get toi_bot_stt::speechTT :definition-)
      "string query
string response
string intent
")



(provide :toi_bot_stt/speechTT "c2e0321a6d60d7971f3d93f2eaf3408e")


