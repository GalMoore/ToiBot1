; Auto-generated. Do not edit!


(cl:in-package toi_bot_speakers-msg)


;//! \htmlinclude speakersCommand.msg.html

(cl:defclass <speakersCommand> (roslisp-msg-protocol:ros-message)
  ((response
    :reader response
    :initarg :response
    :type cl:string
    :initform ""))
)

(cl:defclass speakersCommand (<speakersCommand>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <speakersCommand>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'speakersCommand)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name toi_bot_speakers-msg:<speakersCommand> is deprecated: use toi_bot_speakers-msg:speakersCommand instead.")))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <speakersCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_speakers-msg:response-val is deprecated.  Use toi_bot_speakers-msg:response instead.")
  (response m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <speakersCommand>) ostream)
  "Serializes a message object of type '<speakersCommand>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'response))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'response))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <speakersCommand>) istream)
  "Deserializes a message object of type '<speakersCommand>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'response) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'response) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<speakersCommand>)))
  "Returns string type for a message object of type '<speakersCommand>"
  "toi_bot_speakers/speakersCommand")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'speakersCommand)))
  "Returns string type for a message object of type 'speakersCommand"
  "toi_bot_speakers/speakersCommand")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<speakersCommand>)))
  "Returns md5sum for a message object of type '<speakersCommand>"
  "6de314e2dc76fbff2b6244a6ad70b68d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'speakersCommand)))
  "Returns md5sum for a message object of type 'speakersCommand"
  "6de314e2dc76fbff2b6244a6ad70b68d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<speakersCommand>)))
  "Returns full string definition for message of type '<speakersCommand>"
  (cl:format cl:nil "string response~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'speakersCommand)))
  "Returns full string definition for message of type 'speakersCommand"
  (cl:format cl:nil "string response~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <speakersCommand>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'response))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <speakersCommand>))
  "Converts a ROS message object to a list"
  (cl:list 'speakersCommand
    (cl:cons ':response (response msg))
))
