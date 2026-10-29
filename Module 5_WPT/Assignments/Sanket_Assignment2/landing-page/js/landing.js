/**
 * ==============================================================================
 * NEBULA NITRO ROASTERY - ORDER CALCULATOR ENGINE (landing.js)
 * Author: Sanket Ambre
 * Description: Implements dynamic menu population, cart management, delivery switch,
 *              tier discounts (if/else), reduce calculations, ternary singular/plural,
 *              custom higher-order callback demonstrations, async promise order placement,
 *              and timed promotional banner.
 * ==============================================================================
 */

// 1. Menu Dataset: Array of at least 5 items with id, name, and price
const menuItems = [
  { id: 101, name: "Nitro Cold Brew Infusion (Single Origin)", price: 6.50 },
  { id: 102, name: "Madagascar Vanilla Bean Latte", price: 5.75 },
  { id: 103, name: "Wild Yeast Almond Frangipane Croissant", price: 4.50 },
  { id: 104, name: "Artisanal Sourdough Avocado Tartine", price: 8.25 },
  { id: 105, name: "Signature Espresso Tasting Flight (3 Cups)", price: 9.00 },
  { id: 106, name: "Dark Chocolate Orange Brioche Bun", price: 4.25 }
];

// In-memory Shopping Cart Array
let cart = [];

/**
 * 2. Populate Menu Dropdown using createElement and setAttribute("value", ...)
 */
function buildMenuDropdown() {
  const select = document.getElementById("menu-item-select");
  if (!select) return;

  // Clear existing options except placeholder
  select.innerHTML = '<option value="">-- Choose a Roast or Craft Bake --</option>';

  // Loop through menuItems array
  menuItems.forEach(item => {
    const opt = document.createElement("option");
    // Explicitly use setAttribute for value as instructed in brief
    opt.setAttribute("value", item.id.toString());
    opt.textContent = `${item.name} - $${item.price.toFixed(2)}`;
    select.appendChild(opt);
  });
}

/**
 * 3. Add to Order Handler
 * Reads quantity with parseInt, verifies positive number,
 * updates cart array, and updates order UI.
 */
function addToOrder() {
  const itemSelect = document.getElementById("menu-item-select");
  const qtyInput = document.getElementById("item-quantity-input");
  const errorSpan = document.getElementById("order-qty-error");

  errorSpan.innerHTML = "";

  const selectedId = parseInt(itemSelect.value, 10);
  const quantity = parseInt(qtyInput.value, 10);

  // Validation: Check valid item selected
  if (isNaN(selectedId) || !selectedId) {
    errorSpan.innerHTML = "Please select an item from the menu.";
    return;
  }

  // Validation: Read quantity with parseInt; must be a positive number
  if (isNaN(quantity) || quantity <= 0) {
    errorSpan.innerHTML = "Please enter a valid positive quantity (at least 1).";
    return;
  }

  // Find item in dataset
  const item = menuItems.find(m => m.id === selectedId);
  if (!item) return;

  // Check if item already exists in cart
  const existingCartIndex = cart.findIndex(c => c.id === item.id);
  if (existingCartIndex > -1) {
    cart[existingCartIndex].quantity += quantity;
    cart[existingCartIndex].total = cart[existingCartIndex].quantity * item.price;
  } else {
    // Add item to cart array as an object
    cart.push({
      cartEntryId: Date.now() + Math.random(),
      id: item.id,
      name: item.name,
      price: item.price,
      quantity: quantity,
      total: item.price * quantity
    });
  }

  // Reset inputs
  itemSelect.value = "";
  qtyInput.value = "1";

  // Re-render UI and recalculate bill
  renderCartList();
  calculateBill();
}

/**
 * 4. Render Cart List with createElement and appendChild
 * Every line includes a Remove button that deletes from page and cart array.
 */
function renderCartList() {
  const listContainer = document.getElementById("order-list-container");
  listContainer.innerHTML = "";

  if (cart.length === 0) {
    const emptyMsg = document.createElement("li");
    emptyMsg.style.padding = "16px";
    emptyMsg.style.color = "#64748b";
    emptyMsg.style.textAlign = "center";
    emptyMsg.innerHTML = "<em>Your order cart is currently empty.</em>";
    listContainer.appendChild(emptyMsg);
    return;
  }

  cart.forEach(entry => {
    const li = document.createElement("li");
    li.className = "order-item-row";

    // Item details
    const infoSpan = document.createElement("span");
    infoSpan.innerHTML = `<strong>${entry.name}</strong> &times; ${entry.quantity} @ $${entry.price.toFixed(2)} = <strong>$${entry.total.toFixed(2)}</strong>`;

    // Remove button
    const removeBtn = document.createElement("button");
    removeBtn.className = "btn-remove-item";
    removeBtn.innerHTML = "Remove &times;";
    removeBtn.onclick = function () {
      removeFromCart(entry.cartEntryId);
    };

    li.appendChild(infoSpan);
    li.appendChild(removeBtn);
    listContainer.appendChild(li);
  });
}

/**
 * 5. Remove Item from Cart Array and DOM
 */
function removeFromCart(cartEntryId) {
  // Remove from cart array
  cart = cart.filter(item => item.cartEntryId !== cartEntryId);
  renderCartList();
  calculateBill();
}

/**
 * 6. Delivery Charge Calculator using switch statement
 * Uses switch with case, break, and default to set delivery charge for each area.
 */
function getDeliveryCharge(area) {
  let charge = 0;
  switch (area) {
    case "downtown":
      charge = 3.00;
      break;
    case "metro_suburbs":
      charge = 5.50;
      break;
    case "greater_outskirts":
      charge = 8.00;
      break;
    case "express_priority":
      charge = 12.00;
      break;
    case "store_pickup":
    default:
      charge = 0.00;
      break;
  }
  return charge;
}

/**
 * 7. Discount Calculator using if, else if ladder
 * Gives 15%, 10%, or 5% discount based on subtotal.
 */
function getDiscountRate(subtotal) {
  let discountPercentage = 0;

  if (subtotal >= 80.00) {
    discountPercentage = 0.15; // 15% discount for orders >= $80
  } else if (subtotal >= 50.00) {
    discountPercentage = 0.10; // 10% discount for orders >= $50
  } else if (subtotal >= 25.00) {
    discountPercentage = 0.05; // 5% discount for orders >= $25
  } else {
    discountPercentage = 0.00; // No discount below $25
  }

  return discountPercentage;
}

/**
 * 8. Custom Callback Higher-Order Function Demonstration
 * A function of our own that accepts another function as an argument.
 * Example: applyRule(amount, rule)
 */
function applyRule(amount, rule) {
  return rule(amount);
}

/**
 * Demonstrates calling applyRule once with an anonymous function
 * and once with an arrow function.
 */
function runCallbackDemonstrations(subtotal) {
  // Call 1: Using an ANONYMOUS FUNCTION to compute eco-friendly packaging fee
  const packagingFee = applyRule(subtotal, function (amt) {
    return amt > 0 ? 1.00 : 0.00;
  });

  // Call 2: Using an ARROW FUNCTION to compute loyalty cashback points credit
  const loyaltyPointsEarned = applyRule(subtotal, amt => Math.floor(amt * 2));

  console.log(`[Callback Demo] Subtotal: $${subtotal.toFixed(2)} | Packaging Fee (via Anonymous Func): $${packagingFee.toFixed(2)} | Loyalty Points (via Arrow Func): ${loyaltyPointsEarned} pts`);
}

/**
 * 9. Calculate Bill
 * - Subtotal calculated with reduce
 * - Delivery charge via switch
 * - Discount via if/else if ladder
 * - Singular/plural formatted with conditional (? :) operator
 * - Template literal displaying subtotal, discount, delivery, and grand total.
 */
function calculateBill() {
  const deliverySelect = document.getElementById("delivery-area-select");
  const billSummaryEl = document.getElementById("bill-summary-display");

  // Calculate Subtotal using Array.prototype.reduce()
  const subtotal = cart.reduce((accumulator, item) => accumulator + item.total, 0);

  // Compute total item count
  const totalItemCount = cart.reduce((sum, item) => sum + item.quantity, 0);

  // Conditional (? :) operator to show "1 item" or "N items" correctly as specified
  const itemCountText = totalItemCount === 1 ? "1 item" : `${totalItemCount} items`;

  // Delivery charge from switch statement
  const deliveryCharge = getDeliveryCharge(deliverySelect.value);

  // Discount from if / else if ladder
  const discountRate = getDiscountRate(subtotal);
  const discountAmount = subtotal * discountRate;

  // Final Total
  const finalTotal = Math.max(0, subtotal - discountAmount + (subtotal > 0 ? deliveryCharge : 0));

  // Run callback demonstrations in console
  runCallbackDemonstrations(subtotal);

  // Format one comprehensive message made with a template literal
  const billTemplate = `
    <div class="bill-line">
      <span>Order Quantity:</span>
      <strong>${itemCountText}</strong>
    </div>
    <div class="bill-line">
      <span>Subtotal:</span>
      <span>$${subtotal.toFixed(2)}</span>
    </div>
    <div class="bill-line" style="color: #16a34a;">
      <span>Discount applied (${(discountRate * 100).toFixed(0)}%):</span>
      <span>-$${discountAmount.toFixed(2)}</span>
    </div>
    <div class="bill-line">
      <span>Delivery Charge:</span>
      <span>$${(subtotal > 0 ? deliveryCharge : 0).toFixed(2)}</span>
    </div>
    <div class="bill-total-line">
      <span>Final Total:</span>
      <span>$${finalTotal.toFixed(2)}</span>
    </div>
  `;

  billSummaryEl.innerHTML = billTemplate;
}

/**
 * 10. Place Order Promise Function
 * Waits 2 seconds with setTimeout, then resolves with an order number,
 * or rejects with a message if the cart is empty.
 */
function processOrderPromise() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (cart.length === 0) {
        reject("Your order cannot be placed because the cart is empty. Please add items.");
      } else {
        const orderId = "NEBULA-" + Math.floor(10000 + Math.random() * 90000);
        resolve({
          orderId,
          timestamp: new Date().toLocaleTimeString(),
          itemsCount: cart.length
        });
      }
    }, 2000);
  });
}

/**
 * 11. Async/Await Handler for "Place Order" Button
 * Shows "Placing your order..." while waiting.
 * Handles the promise with async, await, try, and catch.
 */
async function placeOrder() {
  const statusContainer = document.getElementById("order-status-banner");
  const placeBtn = document.getElementById("place-order-btn");

  statusContainer.style.display = "block";
  statusContainer.className = "step-item active";
  statusContainer.innerHTML = "⏳ Placing your order... Communicating with bakery kitchen...";
  placeBtn.disabled = true;

  try {
    // Await promise returned by processOrderPromise
    const confirmation = await processOrderPromise();

    // Order succeeded!
    statusContainer.className = "success-message";
    statusContainer.innerHTML = `
      <h3>🎉 Order Confirmed! (Ref: #${confirmation.orderId})</h3>
      <p>Thank you for choosing Nebula Nitro Roastery. Your order was received at <strong>${confirmation.timestamp}</strong> and is being prepared fresh by our baristas.</p>
    `;

    // Clear cart after successful placement
    cart = [];
    renderCartList();
    calculateBill();
  } catch (errMessage) {
    // Catch rejection
    statusContainer.className = "step-item";
    statusContainer.style.background = "#fee2e2";
    statusContainer.style.borderLeftColor = "#dc2626";
    statusContainer.style.color = "#991b1b";
    statusContainer.innerHTML = `⚠️ ${errMessage}`;
  } finally {
    placeBtn.disabled = false;
  }
}

/**
 * 12. Special Offer Banner
 * A banner that appears 3 seconds after the page loads, using setTimeout,
 * with a promotional message.
 */
function scheduleSpecialOfferBanner() {
  setTimeout(() => {
    const banner = document.getElementById("special-offer-banner");
    if (banner) {
      banner.style.display = "block";
    }
  }, 3000); // 3 seconds delay
}

function dismissSpecialOffer() {
  const banner = document.getElementById("special-offer-banner");
  if (banner) {
    banner.style.display = "none";
  }
}

// Initialization on DOMContentLoaded
window.addEventListener("DOMContentLoaded", () => {
  buildMenuDropdown();
  renderCartList();
  calculateBill();
  scheduleSpecialOfferBanner();
});
