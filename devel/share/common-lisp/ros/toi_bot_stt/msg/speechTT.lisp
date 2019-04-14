; Auto-generated. Do not edit!


(cl:in-package toi_bot_stt-msg)


;//! \htmlinclude speechTT.msg.html

(cl:defclass <speechTT> (roslisp-msg-protocol:ros-message)
  ((query
    :reader query
    :initarg :query
    :type cl:string
    :initform "")
   (response
    :reader response
    :initarg :response
    :type cl:string
    :initform "")
   (intent
    :reader intent
    :initarg :intent
    :type cl:string
    :initform ""))
)

(cl:defclass speechTT (<speechTT>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <speechTT>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'speechTT)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name toi_bot_stt-msg:<speechTT> is deprecated: use toi_bot_stt-msg:speechTT instead.")))

(cl:ensure-generic-function 'query-val :lambda-list '(m))
(cl:defmethod query-val ((m <speechTT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_stt-msg:query-val is deprecated.  Use toi_bot_stt-msg:query instead.")
  (query m))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <speechTT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_stt-msg:response-val is deprecated.  Use toi_bot_stt-msg:response instead.")
  (response m))

(cl:ensure-generic-function 'intent-val :lambda-list '(m))
(cl:defmethod intent-val ((m <speechTT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_stt-msg:intent-val is deprecated.  Use toi_bot_stt-msg:intent instead.")
  (intent m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <speechTT>) ostream)
  "Serializes a message object of type '<speechTT>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'query))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'query))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'response))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'response))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'intent))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'intent))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <speechTT>) istream)
  "Deserializes a message object of type '<speechTT>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'query) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'query) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'response) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'response) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'intent) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'intent) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<speechTT>)))
  "Returns string type for a message object of type '<speechTT>"
  "toi_bot_stt/speechTT")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'speechTT)))
  "Returns string type for a message object of type 'speechTT"
  "toi_bot_stt/speechTT")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<speechTT>)))
  "Returns md5sum for a message object of type '<speechTT>"
  "c2e0321a6d60d7971f3d93f2eaf3408e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'speechTT)))
  "Returns md5sum for a message object of type 'speechTT"
  "c2e0321a6d60d7971f3d93f2eaf3408e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<speechTT>)))
  "Returns full string definition for message of type '<speechTT>"
  (cl:format cl:nil "string query~%string response~%string intent~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'speechTT)))
  "Returns full string definition for message of type 'speechTT"
  (cl:format cl:nil "string query~%string response~%string intent~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <speechTT>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'query))
     4 (cl:length (cl:slot-value msg 'response))
     4 (cl:length (cl:slot-value msg 'intent))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <speechTT>))
  "Converts a ROS message object to a list"
  (cl:list 'speechTT
    (cl:cons ':query (query msg))
    (cl:cons ':response (response msg))
    (cl:cons ':intent (intent msg))
))
