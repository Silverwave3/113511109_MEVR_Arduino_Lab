**`Lab3/Task3-1/report.md`（完整示範報告）**

```markdown
# 課題報告：Task 3-1 timer interrupt & polling

- **學生姓名**：王奕云
- **學生學號**：113511109
- **完成日期**：2026-10-01

---

### 1. 實驗目標(可參考課程投影片寫法)
- 理解 timer interrupt, external interrupt, polling的區別與利弊。
- 學會使用TimerOne函示庫。
- 完成定時中斷的LED電路。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- LED x 2
- 按鈕 x 2
- 1k歐姆電阻 x 2
- 100歐姆電阻 x 2
- 杜邦線 x 9

### 3. 操作說明與成果
1. **連接電路**：先連接兩個相同的按鈕控制LED電路，注意下/上拉電阻。
2. **撰寫程式**：在 Arduino IDE 中寫出控制兩個LED的電路（方式分別為timer interrupt 與 polling）。
3. **燒錄程式**：使用 USB 線連接 Arduino Uno 至電腦，開啟 `Task3-1.ino` 並點擊「上傳」。
4. **實驗成果**：確認兩個LED皆會隨各自按鈕切換狀態，且一個有明顯延遲一個沒有。
5. **操作影片**：錄下操作過程。
