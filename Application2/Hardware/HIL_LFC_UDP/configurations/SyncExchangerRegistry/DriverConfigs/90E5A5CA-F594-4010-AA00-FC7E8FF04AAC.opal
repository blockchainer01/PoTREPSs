OPAL-1.0 Object
DataLogger::Configuration {
  m01_recordMode=Automatic
  m05_useRTCore=0
  m06_verbose=0
  m09_noDataLoss=0
  m13_usageMode=Basic
  m14_logLevel=Minimal
  m15_toolPriority=NORMAL
  m17_showDLTConsole=0
  name=90E5A5CA-F594-4010-AA00-FC7E8FF04AAC_Config2094B04E-2059-4C9C-BC12-2CF6CDCEAE6C
  m10_signalGroupConfigList=90E5A5CA-F594-4010-AA00-FC7E8FF04AAC_Config2094B04E-2059-4C9C-BC12-2CF6CDCEAE6C/SignalGroupConfigList
  parent=/
}
IOConfigListMap<DataLogger::SignalGroupConfig> {
  resizable=1
  uiName=SIGNAL_GROUP_
  name=90E5A5CA-F594-4010-AA00-FC7E8FF04AAC_Config2094B04E-2059-4C9C-BC12-2CF6CDCEAE6C/SignalGroupConfigList
  items {
    item {
      IOConfigItem_id=SIGNAL_GROUP_1
      isDeletable=1
      listParent=0445DEC1-1A49-4035-AE06-6E6ECA934552-default/SyncExchangerRegistry/24346563-D7AA-4F3B-B0C0-2B04647837EE/90E5A5CA-F594-4010-AA00-FC7E8FF04AAC_Config2094B04E-2059-4C9C-BC12-2CF6CDCEAE6C/SignalGroupConfigList
      instance {
        guid=BF9037F7-C018-4269-97A3-3B8D3DEE89A0
        m003_recordMode=Inherit
        m006_exportFormat=OPREC
        m007_fileAutoNaming=1
        m010_fileName=data
        m011_decimationFactor=1
        m015_frameLength=1
        m016_frameLengthUnits=Seconds
        m020_nbRecordedFrames=10
        m021_fileLength=10
        m022_fileLengthUnits=Seconds
        m11_showTriggerConfiguration=1
        m12_triggerReferenceValue=0
        m13_triggerMode=Normal
        m14_triggerFunction=Edge
        m15_triggerPolarity=Positive
        m18_preTriggerPercent=0
        m19_triggerHoldoff=0
        m20_triggerSignalPath=
        m35_enableSubFraming=1
        m36_subFrameSizeMillis=10
      }
    }
  }
  parent=90E5A5CA-F594-4010-AA00-FC7E8FF04AAC_Config2094B04E-2059-4C9C-BC12-2CF6CDCEAE6C
}