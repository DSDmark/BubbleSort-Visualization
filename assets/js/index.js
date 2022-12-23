const canvas = document.getElementById('cvs')
const stopButton = document.getElementById('stopbutton')
const ctx = canvas.getContext('2d')
const CH = (canvas.height = 300)
const CW = (canvas.width = 600)
canvas.style.background = 'black'

const BubbleSort = {
  i: 0,
  j: 0,
  seedValue: [CH],
  loopSpeed: 100,
  isLoop: true,
  borderStyle: { size: 1, color: 'white', style: 'solid' },
  color: 'white',
  sortedLine: null,
  draw() {
    canvas.style.border = `${this.borderStyle.size}px ${this.borderStyle.style} ${this.borderStyle.color}`
    ctx.clearRect(0, 0, CH, CW)
    const lineSpacing = 10
    ctx.lineWidth = 5
<<<<<<< HEAD
    for (let j = 1; j < this.seedValue.length; j++) {
=======
          
    for (let j = 0; j < this.seedValue.length; j++) {
>>>>>>> 141ad495338db7854c07ee1ae9ffeeb6ebc6f429
      const y = j * lineSpacing
      ctx.beginPath()
      ctx.moveTo(y, CH)
      ctx.lineTo(y, CH - this.seedValue[j])
      ctx.closePath()
      if (this.sortedLine === this.seedValue[j]) {
        this.color = 'red'
        ctx.strokeStyle = this.color
        ctx.stroke()
      } else {
        this.color = 'white'
        ctx.strokeStyle = this.color
        ctx.stroke()
      }
    }
  },
  update() {

    if (this.seedValue[this.j] > this.seedValue[this.j + 1]) {
      ;[this.seedValue[this.j], this.seedValue[this.j + 1]] = [
        this.seedValue[this.j + 1],
        this.seedValue[this.j],
      ]
      this.sortedLine = this.seedValue[this.j + 1]
    }
    if (this.i < this.seedValue.length || isClick) {
      this.j++
      if (this.j >= this.seedValue.length - this.i - 1) {
        this.color = 'red'
        this.j = 0
        this.i = this.i + 1
      }
    } else {
      this.isLoop = false
      clearInterval()
    }

    this.draw()
  },
  startup() {
    let range = CW / 20

    for (this.i = 0; this.i <= range; this.i++) {
      this.seedValue[this.i] = Math.random() * (CH - 0 + 1) + 0
    }
    this.i = 0

    // Hendling Evnets.
  },
  stopLoop() {
          clearInterval();
           },
}

// You could use window.requestAnimationFrame as well. but, for simplicity i'm using setInterval.
        let cleaer;
   stopButton.addEventListener('click',()=>{
// p
         //  clearInterval(cleaer);
   }   )
function render() {
  BubbleSort.startup()
             if (BubbleSort.isLoop) { 

    cleaer = setInterval(() => {
      BubbleSort.update(BubbleSort.seedValue)
             
    }, BubbleSort.loopSpeed)
                    }else{
                     console.log("final");
             } 
}

render() // calling the main functions.
