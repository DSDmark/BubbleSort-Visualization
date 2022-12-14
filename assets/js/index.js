const canvas = document.getElementById("cvs");
const ctx = canvas.getContext("2d");

const CH = (canvas.height = 300);
const CW = (canvas.width = 600);
canvas.style.background = "black";
let cond = true;
let i = 0, j = 0;
let value = [CH];
let range = CW / 20;
for (let i = 0; i <= range; i++) {
        value[i] = Math.random() * (CH - 0 + 1) + 0;
}
console.log(value)


const RandomWalker = {
        borderStyle: { size: 1, color: "white", style: "solid" },
        color: "white",
        draw(value) {
                canvas.style.border = `${this.borderStyle.size}px ${this.borderStyle.style} ${this.borderStyle.color}`;
                ctx.clearRect(0, 0, CH, CW);
                const lineSpacing = 10;
                ctx.lineWidth = 5;


                ctx.beginPath();
                for (let j = 0; j < value.length; j++) {
                        const y = j * lineSpacing;
                        ctx.moveTo(y, CH);
                        ctx.lineTo(y, CH - value[j]);

                }
                ctx.closePath();
                ctx.strokeStyle = this.color;
                ctx.stroke();
        },
        update() {


                if (value[j] > value[j + 1]) {
                        [value[j], value[j + 1]] = [value[j + 1], value[j]];
                        this.color = "white"
                }
                if (i < value.length) {
                        j++;
                        console.log(i, j)
                        if (j >= value.length - i - 1) {
                                this.color = "red"
                                j = 0;
                                i = i + 1;
                        }
                } else {

                        cond = false;
                }
                this.draw(value);


        },
        // BubbleSort(arr) {
        //         if (arr.length === 0 || arr.length === 1) return;
        //         // for (let i = 0; i < arr.length; i++) {
        //         //   for (let j = 0; j <= arr.length; j++) {
        //         if (arr[j] > arr[j + 1]) {
        //                 [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
        //         }
        //         // }
        //         // }
        //         return arr;
        // },
};

function render() {
        if (cond) {

                setInterval(() => {
                        RandomWalker.update();
                }, 100)
        }
}

render();
