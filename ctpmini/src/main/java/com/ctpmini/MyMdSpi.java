import com.ctpmini.mdapi.*;

public class MyMdSpi extends CThostFtdcMdSpi {

    private final CThostFtdcMdApi mdApi;

    public MyMdSpi(CThostFtdcMdApi mdApi) {
        this.mdApi = mdApi;
    }

    @Override
    public void OnFrontConnected() {
        System.out.println("行情前置已连接，开始登录...");
        CThostFtdcReqUserLoginField req = new CThostFtdcReqUserLoginField();
        req.setBrokerID("0086");
        mdApi.ReqUserLogin(req, 1);
    }

    @Override
    public void OnRspUserLogin(CThostFtdcRspUserLoginField pRspUserLogin,
                               CThostFtdcRspInfoField pRspInfo,
                               int nRequestID, boolean bIsLast) {
        if (pRspInfo == null || pRspInfo.getErrorID() == 0) {
            System.out.println("行情登录成功，交易日: " + pRspUserLogin.getTradingDay());
            // 订阅行情
            mdApi.SubscribeMarketData(new String[]{"IF2506", "cu2506"});
        } else {
            System.err.println("行情登录失败: " + pRspInfo.getErrorMsg());
        }
    }

    @Override
    public void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField pDepthMarketData) {
        System.out.printf("[%s] 合约=%s 最新价=%.2f 买一=%.2f 卖一=%.2f%n",
                pDepthMarketData.getUpdateTime(),
                pDepthMarketData.getInstrumentID(),
                pDepthMarketData.getLastPrice(),
                pDepthMarketData.getBidPrice1(),
                pDepthMarketData.getAskPrice1());
    }
}
