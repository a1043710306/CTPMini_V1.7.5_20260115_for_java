package com.ctpmini.struct;

/**
 * 响应信息
 * 对应 C++ 结构体: CThostFtdcRspInfoField
 */
public class CThostFtdcRspInfoField {
    /** 错误代码 */
    public int ErrorID;
    /** 错误信息 (最大81字节) */
    public String ErrorMsg;
    /** 本次查询成功记录数 */
    public int RecordCount;

    @Override
    public String toString() {
        return "CThostFtdcRspInfoField{ErrorID=" + ErrorID + ", ErrorMsg='" + ErrorMsg + "', RecordCount=" + RecordCount + "}";
    }
}
