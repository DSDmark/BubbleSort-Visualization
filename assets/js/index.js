const canvas = document.getElementById('cvs')
const toggleButton = document.getElementById('toggleButton')
const speedOfSwaping = document.getElementById('speedofswaping')
const sizeofcanvas = document.getElementById('sizeofcanvas')
const numsoflines = document.getElementById('numberoflines')
const sortedlinecolor = document.getElementById('sortedlinecolor')
const linescolors = document.getElementById('linescolors')

const ctx = canvas.getContext('2d')
const CH = (canvas.height = 300)
const CW = (canvas.width = 600)
canvas.style.background = 'black'

const BubbleSort = {
  i: 0,
  j: 0,
  seedValue: [CH],
  loopSpeed: 200,
  clear: null,
  isLoop: true,
  borderStyle: { size: 1, color: 'white', style: 'solid' },
  color: 'white',
  linesColor: 'white',
  sortingLineColor: 'red',
  sortedLine: null,
  draw() {
    canvas.style.border = `${this.borderStyle.size}px ${this.borderStyle.style} ${this.borderStyle.color}`
    ctx.clearRect(0, 0, CH, CW)
    const lineSpacing = 10
    ctx.lineWidth = 5
    for (let j = 1; j < this.seedValue.length; j++) {
      for (let j = 0; j < this.seedValue.length; j++) {
        const y = j * lineSpacing
        ctx.beginPath()
        ctx.moveTo(y, CH)
        ctx.lineTo(y, CH - this.seedValue[j])
        ctx.closePath()
        if (this.sortedLine === this.seedValue[j]) {
          this.color = this.sortingLineColor
          ctx.strokeStyle = this.color
          ctx.stroke()
        } else {
          this.color = this.linesColor
          ctx.strokeStyle = this.color
          ctx.stroke()
        }
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
    if (this.i < this.seedValue.length) {
      this.j++
      if (this.j >= this.seedValue.length - this.i - 1) {
        this.j = 0
        this.i = this.i + 1
      }
    } else {
      this.isLoop = false
      clearInterval(this.clear)
    }

    this.draw()
  },
  startup() {
    let range = CW / 20

    for (this.i = 0; this.i <= range; this.i++) {
      this.seedValue[this.i] = Math.random() * (CH - 0 + 1) + 0
    }
    this.i = 0
  },

  speedControl(e) {
    this.stopInterval()
    this.isLoop = false
    this.loopSpeed = e
    this.startInterval()
    this.isLoop = true
  },
  stopInterval() {
    clearInterval(this.clear)
  },
  startInterval() {
    // You could use window.requestAnimationFrame as well. but, for simplicity i'm using setInterval.
    this.clear = setInterval(() => {
      this.update(this.seedValue)
    }, this.loopSpeed)
  },
  linescolorsChange(color, lineType = false) {
    this.stopInterval()
    lineType ? (this.sortingLineColor = color) : (this.linesColor = color)
    this.startInterval()
  },
}

// Hendling the events
sortedlinecolor.addEventListener('focusout', (e) => {
  let colorValue = e.target.value
  colorValue = colorValue
    .toLowerCase()
    .toString()
    .replace(/[^a-z]/g, '')
  if (!(colorValue === '')) {
    BubbleSort.linescolorsChange(colorValue, true)
  }
})

linescolors.addEventListener('focusout', (e) => {
  let colorValue = e.target.value
  colorValue = colorValue
    .toLowerCase()
    .toString()
    .replace(/[^a-z]/g, '')
  if (!(colorValue === '')) {
    BubbleSort.linescolorsChange(colorValue)
  }
})

toggleButton.addEventListener('click', () => {
  if (BubbleSort.isLoop) {
    BubbleSort.stopInterval()
    BubbleSort.isLoop = false
  } else {
    BubbleSort.startInterval()
    BubbleSort.isLoop = true
  }
})

speedOfSwaping.addEventListener('change', (e) => {
  document.getElementById('showValue').innerText = e.target.value
  BubbleSort.speedControl(e.target.value)
})

function render() {
  BubbleSort.startup()
  BubbleSort.startInterval()
}

render() // calling the main functions.
